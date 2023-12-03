#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
vector<pair<int, int>> adj[15];
const int INF = 1000000007;
int N, K, H, D, v[501][501], cnt = 0, G[501][501], ans = INF, src, dst;
char ch;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool v2[15];
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < N;
}
void bfs(int sy, int sx)
{
	memset(v, -1, sizeof(v));
	v[sy][sx] = 0;
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || v[ny][nx] >= 0) continue;
			v[ny][nx] = v[y][x] + 1;
			if (G[ny][nx] >= 0) adj[G[sy][sx]].push_back({ G[ny][nx], v[ny][nx] });
			q.push({ ny, nx });
		}
	}
}
void solve(int here, int health, int l, bool first)
{
	if (ans < l) return;
	if (here == dst)
	{
		ans = l;
		return;
	}
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		int cost = adj[here][i].second;
		if (v2[there]) continue;
		if (first)
		{
			if (health < cost) continue;
			v2[there] = true;
			solve(there, health - cost, l + cost, false);
			v2[there] = false;
		}
		else
		{
			if (health + D < cost) continue;
			v2[there] = true;
			solve(there, health - ((D < cost) ? (cost - D) : 0), l + cost, false);
			v2[there] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> H >> D;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			if (ch == 'S') src = cnt;
			if (ch == 'E') dst = cnt;
			if (ch != '.') G[i][j] = cnt++;
			else G[i][j] = -1;
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (G[i][j] >= 0)
				bfs(i, j);
	v2[src] = true;
	solve(src, H, 0, true);
	if (ans == INF) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/22944