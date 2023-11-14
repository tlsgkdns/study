#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int Rf, Cf, Rh, Ch, N, M, A[1001][1001], v[1001][1001][2], ans = -1;
bool R[1001], C[1001];
int dy[4] = { -1, 1,0,0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y > 0 && x > 0 && y <= N && x <= M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M;
	cin >> Rf >> Cf >> Rh >> Ch;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
	v[Rf][Cf][0] = 0;
	queue<pair<pair<int, int>, bool>> q;
	q.push({ {Rf, Cf}, false });
	while (!q.empty() && ans < 0)
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		bool b = q.front().second;
		q.pop();
		if (y == Rh && x == Ch)
		{
			ans = v[y][x][b];
			break;
		}
		for (int d = 0; d < 4; d++)
		{
			int ny = y + (dy[d] * A[y][x]);
			int nx = x + (dx[d] * A[y][x]);
			if (!inRange(ny, nx) || v[ny][nx][b] >= 0) continue;
			v[ny][nx][b] = v[y][x][b] + 1;
			if (ny == Rh && nx == Ch)
			{
				ans = v[ny][nx][b];
				break;
			}
			q.push({ {ny, nx}, b });
		}
		if (!b)
		{
			if (!C[x])
			{
				C[x] = true;
				for (int r = 1; r <= N; r++)
				{
					if (r == y || v[r][x][1] >= 0 || abs(r - y) == A[y][x]) continue;
					v[r][x][1] = v[y][x][b] + 1;
					q.push({ {r, x}, 1 });
				}
			}
			if (!R[y])
			{
				R[y] = true;
				for (int c = 1; c <= M; c++)
				{
					if (c == x || v[y][c][1] >= 0 || abs(c - x) == A[y][x]) continue;
					v[y][c][1] = v[y][x][b] + 1;
					q.push({ {y, c}, 1 });
				}
			}

		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/25189