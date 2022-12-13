#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int MAX = 250001;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int N, M, ans = -1;
int v[501][501], dist[501][501];
char ch;
pii src, dst;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N&& x < M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	queue<pii> q;
	memset(v, -1, sizeof(v)); memset(dist, -1, sizeof(dist));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch == '+')
			{
				q.push({ i, j });
				v[i][j] = 0;
			}
			if (ch == 'V')
				src = { i, j };
			if (ch == 'J')
				dst = { i, j };
		}
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
			q.push({ ny, nx });
		}
	}
	priority_queue<pair<int, pii>> pq;
	pq.push({ v[src.first][src.second] , src });
	dist[src.first][src.second] = v[src.first][src.second];
	while (!pq.empty())
	{
		int c = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (dist[y][x] < c) continue;
		if (make_pair(y, x) == dst)
		{
			ans = c;
			break;
		}
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx)) continue;
			int md = min(c, v[ny][nx]);
			if (dist[ny][nx] >= md) continue;
			dist[ny][nx] = md;
			pq.push({ md, {ny, nx} });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2917