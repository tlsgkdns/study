#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using pii = pair<int, int>;
pii src;
int N, B[11][11], v[11][11][3][101], ans = 0;
int dy[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dx[8] = { -2, 2, -2, 2, -1, 1, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> B[i][j];
			if (B[i][j] == 1)
				src = { i, j };
		}
	queue<pair<pii, pii>> q;
	for (int i = 0; i < 3; i++)
	{
		v[src.first][src.second][i][1] = 0;
		q.push({ src, {i, 1} });
	}
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int k = q.front().second.first;
		int c = q.front().second.second;
		q.pop();
		if (c == N * N)
		{
			ans = v[y][x][k][c];
			break;
		}
		for (int i = 0; i < 3; i++)
		{
			if (i == k || v[y][x][i][c] >= 0) continue;
			v[y][x][i][c] = v[y][x][k][c] + 1;
			q.push({ {y, x}, {i, c} });
		}
		if (k == 2)
		{
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					if (i - j == y - x || i + j == y + x)
					{
						int nc = c;
						if (B[i][j] == c + 1) ++nc;
						if (v[i][j][k][nc] >= 0) continue;
						v[i][j][k][nc] = v[y][x][k][c] + 1;
						q.push({ {i, j}, {k, nc} });
					}
		}
		else if (k == 0)
		{
			for (int d = 0; d < 8; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				int nc = c;
				if (B[ny][nx] == c + 1) ++nc;
				if (!inRange(ny, nx) || v[ny][nx][k][nc] >= 0) continue;
				v[ny][nx][k][nc] = v[y][x][k][c] + 1;
				q.push({ {ny, nx}, {k, nc} });
			}
		}
		else
		{
			for (int ny = 0; ny < N; ny++)
			{
				int nc = c;
				if (B[ny][x] == c + 1) ++nc;
				if (v[ny][x][k][nc] >= 0) continue;
				v[ny][x][k][nc] = v[y][x][k][c] + 1;
				q.push({ {ny, x}, {k, nc} });
			}
			for (int nx = 0; nx < N; nx++)
			{
				int nc = c;
				if (B[y][nx] == c + 1) ++nc;
				if (v[y][nx][k][nc] >= 0) continue;
				v[y][nx][k][nc] = v[y][x][k][c] + 1;
				q.push({ {y, nx}, {k, nc} });
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16959