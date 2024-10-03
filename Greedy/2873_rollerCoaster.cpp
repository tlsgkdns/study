#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int R, C, P[1001][1001];
string ans = "";
char getOp(char ch)
{
	if (ch == 'R') return 'L';
	if (ch == 'L') return 'R';
	if (ch == 'U') return 'D';
	return 'U';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> P[i][j];
	if (R % 2 > 0)
	{
		char c = 'R';
		for (int d = 0; d < R; d++)
		{
			for (int i = 0; i < C - 1; i++)
				ans.push_back(c);
			ans.push_back('D');
			c = getOp(c);
		}
		ans.pop_back();
	}
	else if (C % 2 > 0)
	{
		char c = 'D';
		for (int r = 0; r < C; r++)
		{
			for (int i = 0; i < R - 1; i++)
				ans.push_back(c);
			ans.push_back('R');
			c = getOp(c);
		}
		ans.pop_back();
	}
	else
	{
		int tr = 0, tc = 0, m = 1001;
		for (int y = 0; y < R; y++)
			for (int x = 0; x < C; x++)
				if (m > P[y][x] && (y + x) % 2 == 1)
				{
					m = P[y][x];
					tr = y; tc = x;
				}
		char c = 'R';
		for (int r = 0; r < R; r += 2)
		{
			bool f = false;
			if (r <= tr && tr <= r + 1)
			{
				char d = 'D';
				int y = r, x = 0;
				for (int j = 0; j < C - 1; j++)
				{
					for (int i = 0; i < 2 && j < C - 1; i++)
					{
						if (i == 0)
						{
							y += ((d == 'D') ? 1 : -1);
							if (tr == y && tc == x)
							{
								if (c == 'R') ++x;
								else --x;
								ans.push_back(c);
								++j;
							}
							ans.push_back(d);
							d = getOp(d);
						}
						else
						{
							if (c == 'L') --x;
							else ++x;
							ans.push_back(c);
						}
					}
				}
				f = true;
				if (y < R - 1)
				{
					ans.push_back('D');
					if (y % 2 == 0 && r + 2 < R) ans.push_back('D');
				}
			}
			else
			{
				for (int i = 0; i < C - 1; i++)
					ans.push_back(c);
				ans.push_back('D');
				for (int i = 0; i < C - 1; i++)
					ans.push_back(getOp(c));
				if (r + 2 < R)
				{
					ans.push_back('D');
				}
			}
			if (f) c = 'L';
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2873