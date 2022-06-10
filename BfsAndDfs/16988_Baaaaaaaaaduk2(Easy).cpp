#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int board[21][21];
bool v[21][21];
int N, M, ans = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < N && x < M);
}

int solve()
{
	memset(v, false, sizeof(v));
	queue<pair<int, int>> q;
	int s = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (v[i][j] || board[i][j] != 2) continue;
			int cnt = 1, closed = true;
			queue<pair<int, int>> q;
			q.push({ i, j });
			v[i][j] = true;
			while (!q.empty())
			{
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for (int d = 0; d < 4; d++)
				{
					int ny = y + dy[d];
					int nx = x + dx[d];
					if (!inRange(ny, nx) || v[ny][nx]) continue;
					if (board[ny][nx] == 0)
					{
						closed = false;
						continue;
					}
					if (board[ny][nx] == 2)
					{
						v[ny][nx] = true;
						q.push({ ny, nx });
						cnt++;
					}
				}
			}
			if (closed) s += cnt;
		}
	return s;
}
void solve2(int y, int x, int d)
{
	if (d == 2)
	{
		ans = max(ans, solve());
		return;
	}
	if (y == N) return;
	int ny = (x == M - 1) ? y + 1 : y;
	int nx = (x == M - 1) ? 0 : x + 1;
	solve2(ny, nx, d);
	if (board[y][x] == 0)
	{
		board[y][x] = 1;
		solve2(ny, nx, d + 1);
		board[y][x] = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	solve2(0, 0, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16988