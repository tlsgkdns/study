#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 1000000007;
int N, M, T, D, H[53][53], C[626][626], ans = 0, Z[626][626];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
char ch;
priority_queue<pair<int, pair<int, int>>> pq;

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
int dijkstra(int sy, int sx)
{
	for (int i = 0; i < N * M; i++)
		for (int j = 0; j < N * M; j++)
			C[i][j] = INF;
	pq.push({ 0, {sy, sx} });
	C[sy][sx] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (C[y][x] < cost) continue;
		if (y == 0 && x == 0) return cost;
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || abs(H[ny][nx] - H[y][x]) > T) continue;
			int nxtCost = cost;
			if (H[ny][nx] > H[y][x])
				nxtCost += (int)pow(H[ny][nx] - H[y][x], 2);
			else
				++nxtCost;
			if (C[ny][nx] > nxtCost)
			{
				C[ny][nx] = nxtCost;
				pq.push({ -nxtCost, {ny, nx} });
			}
		}
	}

	return INF;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> T >> D;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch >= 'A' && ch <= 'Z') H[i][j] = ch - 'A';
			else H[i][j] = (ch - 'a') + 26;
		}
	for (int i = 0; i < N * M; i++)
		for (int j = 0; j < N * M; j++)
			Z[i][j] = INF;
	pq.push({ 0, {0, 0} });
	Z[0][0] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (Z[y][x] < cost) continue;
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || abs(H[ny][nx] - H[y][x]) > T) continue;
			int nxtCost = cost;
			if (H[ny][nx] > H[y][x])
				nxtCost += (int)pow(H[ny][nx] - H[y][x], 2);
			else
				++nxtCost;
			if (Z[ny][nx] > nxtCost)
			{
				Z[ny][nx] = nxtCost;
				pq.push({ -nxtCost, {ny, nx} });
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ans < H[i][j] && dijkstra(i, j) + Z[i][j] <= D)
				ans = H[i][j];
		}
	}
	cout << ans << '\n';
}


// https://www.acmicpc.net/problem/1486