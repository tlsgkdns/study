#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M, v[2002][2002], sy = -1, sx = -1, ey = 0, ex = 0, dist = 0;
char Z[2002][2002];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
bool ed(int y, int x)
{
	return y == 0 || x == 0 || y == N - 1 || x == M - 1;
}
bool dfs(int y, int x)
{
	if (v[y][x] > dist) return false;
	if (v[y][x] == dist)
	{
		return (y == ey && x == ex);
	}
	for (int d = 0; d < 4; d++)
	{
		int ny = dy[d] + y;
		int nx = dx[d] + x;
		if (!inRange(ny, nx) || v[ny][nx] >= 0 || Z[ny][nx] == '+') continue;
		v[ny][nx] = v[y][x] + 1;
		if (dfs(ny, nx))
		{
			Z[y][x] = '.';
			return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> Z[i][j];
			if (Z[i][j] == '.')
			{
				if ((i == 0 || j == 0 || i == N - 1 || j == M - 1) && sy < 0)
				{
					sy = i;
					sx = j;
				}
				Z[i][j] = '@';
			}
		}
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	v[sy][sx] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if ((sy != y || sx != x) && ed(y, x))
		{
			ey = y;
			ex = x;
			dist = v[y][x];
			break;
		}
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || Z[ny][nx] == '+' || v[ny][nx] >= 0) continue;
			v[ny][nx] = v[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	memset(v, -1, sizeof(v));
	Z[sy][sx] = Z[ey][ex] = '.';
	v[sy][sx] = 0;
	dfs(sy, sx);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << Z[i][j];
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/24463