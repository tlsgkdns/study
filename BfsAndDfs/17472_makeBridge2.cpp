#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> island, adj;
vector<pair<int, pair<int, int>>> edge;
const int mVal = 1000000000, iNum = 10;
int N, M, ans = 0;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
bool chk;
struct UF
{
	vector<int> parent;
	UF()
	{
		parent.resize(iNum);
		for (int i = 0; i < iNum; i++)
			parent[i] = i;
	}
	int find(int u)
	{
		if (u == parent[u])
			return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v)
	{
		chk = false;
		u = find(u);
		v = find(v);
		if (u == v) return;
		parent[u] = v;
		chk = true;
	}
	bool allConnect(int mx)
	{
		int c = find(1);
		bool ret = true;
		for (int i = 1; i <= mx; i++)
			if (c != find(i)) ret = false;
		return ret;
	}
};
void dfs(int y, int x, int group)
{
	island[y][x] = group;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || island[ny][nx] != 1) continue;
		dfs(ny, nx, group);
	}
}

void bfs(int y, int x, int group)
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	for (int i = 0; i < 4; i++)
		q.push(make_pair(make_pair(y, x), make_pair(i, 0)));
	while (!q.empty())
	{
		int y_ = q.front().first.first;
		int x_ = q.front().first.second;
		int idx = q.front().second.first;
		int cnt = q.front().second.second;
		int ny = y_ + dy[idx];
		int nx = x_ + dx[idx];
		q.pop();
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (island[ny][nx] == 0)
			q.push(make_pair(make_pair(ny, nx), make_pair(idx, cnt + 1)));
		else if (island[ny][nx] != group && cnt > 1)
		{
			adj[island[ny][nx] - 1][group - 1] = min(adj[island[ny][nx] - 1][group - 1], cnt);
			adj[group - 1][island[ny][nx] - 1] = min(adj[group - 1][island[ny][nx] - 1], cnt);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	island.resize(N, vector<int>(M));
	adj.resize(iNum, vector<int>(iNum, mVal));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> island[i][j];
	int g = 2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (island[i][j] == 1)
			{
				dfs(i, j, g);
				g++;
			}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (island[i][j] != 0)
				bfs(i, j, island[i][j]);
		}
	for (int i = 0; i < iNum; i++)
		for (int j = i; j < iNum; j++)
		{
			if (adj[i][j] == mVal) continue;
			edge.push_back(make_pair(adj[i][j], make_pair(i, j)));
		}
	sort(edge.begin(), edge.end());
	UF uf;
	for (int i = 0; i < edge.size(); i++)
	{
		int val = edge[i].first;
		int from = edge[i].second.first;
		int to = edge[i].second.second;
		uf.merge(from, to);
		if (chk) ans += val;
	}
	if (ans == 0 || !uf.allConnect(g - 2)) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17472