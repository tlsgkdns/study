#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int board[10][10], ans = 0, a = 0, N;
bool l[20], r[20];
void solve(int y, int x, int d)
{
	if (x >= N)
	{
		solve(y + 1, (x % 2 == 0), d);
		return;
	}
	if (y >= N)
	{
		a = max(a, d);
		return;
	}
	if (board[y][x] && !l[y - x + N - 1] && !r[y + x])
	{
		l[y - x + N - 1] = true;
		r[y + x] = true;
		solve(y, x + 2, d + 1);
		l[y - x + N - 1] = false;
		r[y + x] = false;
	}
	solve(y, x + 2, d);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	solve(0, 0, 0);
	ans += a; a = 0;
	solve(0, 1, 0); ans += a;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1799