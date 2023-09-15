#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

char ch;
int N, M, S = 0, v[21][21], ans = 100000;
bool T[21][21];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			T[i][j] = ch - '0';
			S += T[i][j];
		}
	for (int r1 = 0; r1 < N; r1++)
		for (int c1 = 0; c1 < M; c1++)
		{
			if (T[r1][c1]) continue;
			for (int r2 = 0; r2 < N; r2++)
				for (int c2 = 0; c2 < M; c2++)
				{
					if (T[r2][c2]) continue;
					int cnt = 0, t = 0;
					queue<pair<int, int>> q;
					memset(v, -1, sizeof(v));
					v[r1][c1] = 0; v[r2][c2] = 0;
					q.push({ r1, c1 }); q.push({ r2, c2 });
					while (!q.empty() && cnt < S)
					{
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						if (ans <= v[y][x]) break;
						for (int d = 0; d < 4; d++)
						{
							int ny = y + dy[d];
							int nx = x + dx[d];
							if (!inRange(ny, nx) || v[ny][nx] >= 0) continue;
							v[ny][nx] = v[y][x] + 1;
							t = max(t, v[ny][nx]);
							if (T[ny][nx])	++cnt;
							q.push({ ny, nx });
						}
					}
					ans = min(ans, t);
				}
		}
	if (ans >= 403) ans = 0;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15812