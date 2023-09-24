#include <iostream>
using namespace std;
int R, C, sy, sx, T, ans = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
char M[101][101];
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < R && x < C;
}
void solve(int y, int x, int s, int t)
{
	ans = (s > ans) ? s : ans;
	if (t == T) return;
	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!inRange(ny, nx) || M[ny][nx] == '#') continue;
		if (M[ny][nx] == 'S')
		{
			M[ny][nx] = '.';
			solve(ny, nx, s + 1, t + 1);
			M[ny][nx] = 'S';
		}
		else
			solve(ny, nx, s, t + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == 'G')
			{
				M[i][j] = '.';
				sy = i;
				sx = j;
			}
		}
	solve(sy, sx, 0, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/21772