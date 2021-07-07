#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> g;
vector<vector<char>> lake;
pair<int, int> src = { -1, -1 }, dst;
int r, c, ans = 0;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

struct Dset
{
	vector<int> parent, rank;
	Dset(int n) : parent(n), rank(n, 1)
	{
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int u)
	{
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v)
	{
		u = find(u); v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
};
void dfs(int y, int x, int gNum)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c || g[ny][nx] != -1 || lake[ny][nx] == 'X') continue;
		g[ny][nx] = gNum;
		dfs(ny, nx, gNum);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	lake.resize(r, vector<char>(c)); g.resize(r, vector<int>(c, -1));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			cin >> lake[i][j];
			if (lake[i][j] == 'L')
			{
				if (src.first == -1)
					src = { i, j };
				else
					dst = { i, j };
			}
		}
	queue<pair<int, int>> q;
	int gNum = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (lake[i][j] != 'X' && g[i][j] == -1)
			{
				g[i][j] = gNum;
				dfs(i, j, gNum);
				q.push(make_pair(i, j));
				gNum++;
			}
	Dset dset(gNum);
	vector<vector<bool>> v(r, vector<bool>(c, false));
	lake;
	while (dset.find(g[src.first][src.second]) != dset.find(g[dst.first][dst.second]))
	{
		lake; g;
		queue<pair<int, int>> buf;
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= r || nx >= c || v[ny][nx]) continue;
				v[ny][nx] = true;
				if (lake[ny][nx] == 'X')
				{
					lake[ny][nx] = '.';
					g[ny][nx] = g[y][x];
					buf.push({ ny, nx });
					continue;
				}
				else if (dset.find(g[ny][nx]) != dset.find(g[y][x]))
				{
					dset.merge(g[ny][nx], g[y][x]);
				}
				q.push(make_pair(ny, nx));
			}
		}
		while (!buf.empty())
		{
			pair<int, int> p = buf.front();
			q.push(p);
			for (int i = 0; i < 4; i++)
			{
				int f = p.first + dy[i];
				int s = p.second + dx[i];
				if (f < 0 || s < 0 || f >= r || s >= c || lake[f][s] == 'X') continue;
				if (dset.find(g[f][s]) != dset.find(g[p.first][p.second]))
					dset.merge(g[f][s], g[p.first][p.second]);
			}
			buf.pop();
		}
		ans++;
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/3197