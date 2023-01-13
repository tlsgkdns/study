#include <iostream>
#include <algorithm>
using namespace std;

char ch;
int B[10][10], ans = 1001;

void click(int y, int x)
{
	if (x > 0) ++B[y][x - 1];
	if (x < 9) ++B[y][x + 1];
	if (y > 0) ++B[y - 1][x];
	if (y < 9) ++B[y + 1][x];
	++B[y][x];
}
void unClick(int y, int x)
{
	if (x > 0) --B[y][x - 1];
	if (x < 9) --B[y][x + 1];
	if (y > 0) --B[y - 1][x];
	if (y < 9) --B[y + 1][x];
	--B[y][x];
}
void solve2(int y, int x, int d)
{
	if (y == 10)
	{
		for (int i = 0; i < 10; i++)
			if (B[9][i] % 2 == 0) return;
		ans = min(ans, d);
		return;
	}
	if (x == 10)
	{
		solve2(y + 1, 0, d);
		return;
	}
	if (B[y - 1][x] % 2 == 0)
	{
		click(y, x);
		solve2(y, x + 1, d + 1);
		unClick(y, x);
	}
	else
		solve2(y, x + 1, d);
}
void solve(int idx, int d)
{
	if (idx == 10)
	{
		solve2(1, 0, d);
		return;
	}
	solve(idx + 1, d);
	click(0, idx);
	solve(idx + 1, d + 1);
	unClick(0, idx);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			cin >> ch;
			if (ch == 'O') B[i][j] = 0;
			else B[i][j] = 1;
		}
	solve(0, 0);
	if (ans == 1001) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14939