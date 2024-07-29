#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1000000007;
int N, M, rcnt = 1, D[1001][1001], ans = INF, adj[22][22];
bool R[1001][1001];
char ch;
pair<int, int> pos[22];
int dy[4] = { -1, 1, 0,0 };
int dx[4] = { 0, 0, -1, 1 };
bool v[22];
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
void bfs(int s)
{
	memset(D, -1, sizeof(D));
	queue<pair<int, int>> q;
	q.push(pos[s]);
	D[pos[s].first][pos[s].second] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || R[ny][nx] || D[ny][nx] >= 0) continue;
			D[ny][nx] = D[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	for (int i = 0; i < rcnt; i++)
		adj[s][i] = D[pos[i].first][pos[i].second];
}
void solve(int here, int cnt, int s)
{
	if (ans <= s) return;
	if (cnt == 5)
	{
		ans = s;
		return;
	}
	for (int there = 1; there < rcnt; there++)
	{
		if (v[there] || adj[here][there] < 0) continue;
		v[there] = true;
		solve(there, cnt + 1, s + adj[here][there]);
		v[there] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(D, -1, sizeof(D));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch == 'X') R[i][j] = true;
			if (ch == 'S') pos[0] = { i, j };
			if (ch == 'K') pos[rcnt++] = { i, j };
		}
	for (int i = 0; i < rcnt; i++) bfs(i);
	v[0] = true;
	solve(0, 0, 0);
	if (ans >= INF) cout << -1 << '\n';
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/23817