#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, ans = 2501, S = 0;
int lab[51][51], v[51][51];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < N;
}

int bfs()
{
	memset(v, -1, sizeof(v));
	queue<pair<int, int>> q;
	int f = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (lab[i][j] == 3)
			{
				q.push({ i, j });
				v[i][j] = 0;
				f++;
			}
		}
	int ret = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || v[ny][nx] != -1 || lab[ny][nx] == 1) continue;
			q.push({ ny, nx });
			v[ny][nx] = v[y][x] + 1;
			ret = max(v[ny][nx], ret);
			f++;
		}
	}
	ret = (S == f) ? ret : -1;
	return ret;
}

void solve(int y, int x, int d)
{
	if (d == M)
	{
		int a = bfs();
		if (a >= 0) ans = min(a, ans);
		return;
	}
	if (y == N) return;
	if (x == N)
	{
		solve(y + 1, 0, d);
		return;
	}
	if (lab[y][x] < 2)
	{
		solve(y, x + 1, d);
		return;
	}
	lab[y][x] = 3;
	solve(y, x + 1, d + 1);
	lab[y][x] = 2;
	solve(y, x + 1, d);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> lab[i][j];
			if (lab[i][j] != 1) S++;
		}
	solve(0, 0, 0);
	if (ans == 2501) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17141