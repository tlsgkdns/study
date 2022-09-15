#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

char ans[8][8], ans2[8][8];
bool confirm = false;
int farm[8][8], M, K, tmp[8][8], S = 0, pl = 0, mi = 0;

void solve(int y, int x)
{
	if (confirm) return;
	if (x == 8)
	{
		for (int i = 0; i < y; i++)
			if (tmp[y][i] != farm[y][i])
				return;
		if (y == 7)
		{
			memcpy(ans2, ans, sizeof(ans));
			confirm = true;
			return;
		}
		solve(y + 1, y);
		return;
	}
	if (y == 8)
	{
		for (int i = 0; i <= x; i++)
			if (tmp[i][x] != farm[i][x])
				return;
		solve(x + 1, x + 1);
		return;
	}
	if (ans[y][x] != '.')
	{
		if (pl > 0)
		{
			tmp[y][x]++;
			for (int r = 0; r < 8; r++)
			{
				if (r == y) continue;
				tmp[r][x]++;
			}
			for (int c = 0; c < 8; c++)
			{
				if (c == x) continue;
				tmp[y][c]++;
			}
			ans[y][x] = '+';
			pl--;
			if (y <= x) solve(y, x + 1);
			else solve(y + 1, x);
			ans[y][x] = '?';
			tmp[y][x]--;
			for (int r = 0; r < 8; r++)
			{
				if (r == y) continue;
				tmp[r][x]--;
			}
			for (int c = 0; c < 8; c++)
			{
				if (c == x) continue;
				tmp[y][c]--;
			}
			pl++;
		}
		if (mi > 0)
		{
			tmp[y][x]--;
			for (int r = 0; r < 8; r++)
			{
				if (r == y) continue;
				tmp[r][x]--;
			}
			for (int c = 0; c < 8; c++)
			{
				if (c == x) continue;
				tmp[y][c]--;
			}
			ans[y][x] = '-';
			mi--;
			if (y <= x) solve(y, x + 1);
			else solve(y + 1, x);
			tmp[y][x]++;
			for (int r = 0; r < 8; r++)
			{
				if (r == y) continue;
				tmp[r][x]++;
			}
			for (int c = 0; c < 8; c++)
			{
				if (c == x) continue;
				tmp[y][c]++;
			}
			ans[y][x] = '?';
			mi++;
		}
	}
	else
	{
		if (y <= x) solve(y, x + 1);
		else solve(y + 1, x);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> K;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			cin >> farm[i][j];
			farm[i][j] -= M;
			S += farm[i][j];
		}
	S /= 15;
	pl = (K + S) / 2; mi = (K - S) / 2;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			int s = farm[i][j];
			for (int r = 0; r < 8; r++)
			{
				if (r == i) continue;
				s += farm[r][j];
			}
			for (int c = 0; c < 8; c++)
			{
				if (c == j) continue;
				s += farm[i][c];
			}
			if (abs(s) % 2 == 1)
				ans[i][j] = '?';
			else
				ans[i][j] = '.';
		}
	solve(0, 0);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << ans2[i][j] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2514