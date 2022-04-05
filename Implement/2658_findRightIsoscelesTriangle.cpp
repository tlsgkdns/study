#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using pii = pair<int, int>;
char ch;
int s = 0;
int grid[10][10];
vector<pii> ans = { make_pair(-1, -1), make_pair(-1, -1), make_pair(-1, -1) };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < 10 && x < 10;
}
bool condition1(int y, int x, int l)
{
	int sy = y, sx = x + l, ny = y + l, nx = x;
	if (!inRange(sy, sx) || !inRange(ny, nx) || grid[ny][nx] == 0) return false;
	while (sy != ny)
	{
		if (grid[sy][sx] == 0) return false;
		sy++;
		sx--;
	}
	return true;
}
bool condition2(int y, int x, int l)
{
	int sy = y, sx = x + l, ny = y - l, nx = x;
	if (!inRange(sy, sx) || !inRange(ny, nx) || grid[ny][nx] == 0) return false;
	while (sy != ny)
	{
		if (grid[sy][sx] == 0) return false;
		sy--;
		sx--;
	}
	return true;
}
bool condition3(int y, int x, int l)
{
	int sy = y, sx = x - l, ny = y - l, nx = x;
	if (!inRange(sy, sx) || !inRange(ny, nx) || grid[ny][nx] == 0) return false;
	while (sy != ny)
	{
		if (grid[sy][sx] == 0) return false;
		sy--;
		sx++;
	}
	return true;
}
bool condition4(int y, int x, int l)
{
	int sy = y, sx = x - l, ny = y + l, nx = x;
	if (!inRange(sy, sx) || !inRange(ny, nx) || grid[ny][nx] == 0) return false;
	while (sy != ny)
	{
		if (grid[sy][sx] == 0) return false;
		sy++;
		sx++;
	}
	return true;
}
bool condition5(int y, int x, int l)
{
	return condition1(y, x, l) && condition2(y, x, l);
}
bool condition6(int y, int x, int l)
{
	return condition2(y, x, l) && condition3(y, x, l);
}
bool condition7(int y, int x, int l)
{
	return condition3(y, x, l) && condition4(y, x, l);
}
bool condition8(int y, int x, int l)
{
	return condition1(y, x, l) && condition4(y, x, l);
}
int checkCondition()
{
	bool chk = true;
	int tmp = 0;
	for (int i = 1; i <= 10; i++)
	{
		tmp += i;
		if (tmp > s) return -1;
		if (tmp == s)
			return i - 1;
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			cin >> ch;
			grid[i][j] = ch - '0';
			if (grid[i][j] == 1) s++;
		}
	int sq = (int)sqrt(s);
	if ((sq * sq) == s)
	{
		bool br = false;
		int n = sqrt(s) - 1;
		for (int y = 0; y < 10; y++)
		{
			if (br) break;
			for (int x = 0; x < 10; x++)
			{
				if (grid[y][x] == 1)
				{
					bool f = false;
					for (int l = 1; l <= n; l++)
					{
						if (!condition5(y, x, l))
						{
							f = true;
							break;
						}
					}
					if (!f)
					{
						ans[0] = { y - n, x };
						ans[1] = { y, x + n };
						ans[2] = { y + n, x };
						br = true;
						break;
					}
					f = false;
					for (int l = 1; l <= n; l++)
					{
						if (!condition6(y, x, l))
						{
							f = true;
							break;
						}
					}
					if (!f)
					{
						ans[0] = { y - n, x };
						ans[1] = { y, x - n };
						ans[2] = { y, x + n };
						br = true;
						break;
					}
					f = false;
					for (int l = 1; l <= n; l++)
					{
						if (!condition7(y, x, l))
						{
							f = true;
							break;
						}
					}
					if (!f)
					{
						ans[0] = { y - n, x };
						ans[1] = { y, x - n };
						ans[2] = { y + n, x };
						br = true;
						break;
					}
					f = false;
					for (int l = 1; l <= n; l++)
					{
						if (!condition8(y, x, l))
						{
							f = true;
							break;
						}
					}
					if (!f)
					{
						ans[0] = { y, x - n };
						ans[1] = { y, x + n };
						ans[2] = { y + n, x };
						br = true;
						break;
					}
				}
			}
		}
	}
	else
	{
		int n = checkCondition();
		if (n != -1)
		{
			bool br = false;
			for (int i = 0; i < 10; i++)
			{
				if (br) break;
				for (int j = 0; j < 10; j++)
				{
					if (grid[i][j] == 1)
					{
						bool f = false;
						for (int l = 1; l <= n; l++)
						{
							if (!condition1(i, j, l))
							{
								f = true;
								break;
							}
						}
						if (!f)
						{
							ans[0] = { i, j };
							ans[1] = { i, j + n };
							ans[2] = { i + n, j };
							br = true;
							break;
						}
						f = false;
						for (int l = 1; l <= n; l++)
						{
							if (!condition2(i, j, l))
							{
								f = true;
								break;
							}
						}
						if (!f)
						{
							ans[0] = { i - n, j };
							ans[1] = { i, j };
							ans[2] = { i, j + n };
							br = true;
							break;
						}
						f = false;
						for (int l = 1; l <= n; l++)
						{
							if (!condition3(i, j, l))
							{
								f = true;
								break;
							}
						}
						if (!f)
						{
							ans[0] = { i - n, j };
							ans[1] = { i, j - n };
							ans[2] = { i, j };
							br = true;
							break;
						}
						f = false;
						for (int l = 1; l <= n; l++)
						{
							if (!condition4(i, j, l))
							{
								f = true;
								break;
							}
						}
						if (!f)
						{
							ans[0] = { i, j - n };
							ans[1] = { i, j };
							ans[2] = { i + n, j };
							br = true;
							break;
						}
					}
				}

			}
		}
	}
	if (ans[0].first == -1) cout << 0 << '\n';
	else
		for (int i = 0; i < 3; i++)
			cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
}

// https://www.acmicpc.net/problem/2658