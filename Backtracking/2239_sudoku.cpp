#include <iostream>
using namespace std;

int B[9][9], N;
char ch;
bool hor[9][10], ver[9][10], sq[9][10];
bool br = false;
int getNum(int y, int x)
{
	return ((y / 3) * 3 + (x / 3));
}
void solve(int pos)
{
	if (br) return;
	if (pos >= 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << B[i][j];
			cout << '\n';
		}
		br = true;
		return;
	}
	int y = pos / 9;
	int x = pos % 9;
	if (B[y][x] > 0)
	{
		solve(pos + 1);
		return;
	}
	for (int n = 1; n <= 9; n++)
		if (!hor[y][n] && !ver[x][n] && !sq[getNum(y, x)][n])
		{
			hor[y][n] = true;
			ver[x][n] = true;
			sq[getNum(y, x)][n] = true;
			B[y][x] = n;
			solve(pos + 1);
			B[y][x] = 0;
			hor[y][n] = false;
			ver[x][n] = false;
			sq[getNum(y, x)][n] = false;
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> ch;
			N = (ch - '0');
			B[i][j] = N;
			if (N > 0)
			{
				hor[i][N] = true;
				ver[j][N] = true;
				sq[getNum(i, j)][N] = true;
			}
		}
	solve(0);
}

// https://www.acmicpc.net/problem/2239