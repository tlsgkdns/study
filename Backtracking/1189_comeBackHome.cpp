#include <iostream>
#include <cstring>
using namespace std;
int R, C, K;
char str[6][6];
bool v[6][6];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ans = 0;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < R && x < C;
}
void solve(int y, int x, int l)
{
	if (y == 0 && x == C - 1)
	{
		if (l == K) ans++;
		return;
	}
	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!inRange(ny, nx) || v[ny][nx] || str[ny][nx] == 'T') continue;
		v[ny][nx] = true;
		solve(ny, nx, l + 1);
		v[ny][nx] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, false, sizeof(v));
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> str[i][j];
	v[R - 1][0] = true;
	solve(R - 1, 0, 1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1189