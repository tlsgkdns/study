#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

char ch[1501][1501];
int R, C, A[1501][1501], B[1501][1501], dp[1501][1501];
string str;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < R&& x < C;
}
int solve(int y, int x)
{
	if (y == R - 1 && x == C - 1) return 0;
	int& ret = dp[y][x];
	if (ret >= 0) return ret;
	if (y < R - 1 && x < C - 1)
		ret = max(ret, solve(y + 1, x + 1) + A[R - 1][x] - A[y][x] + B[y][C - 1] - B[y][x]);
	if (y < R - 1)
		ret = max(ret, solve(y + 1, x) + B[y][C - 1] - B[y][x]);
	if (x < C - 1)
		ret = max(ret, solve(y, x + 1) + A[R - 1][x] - A[y][x]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> str;
			int n = stoi(string(str.begin() + 1, str.end()));
			if (str[0] == 'B')
			{
				if (j == 0) B[i][j] = n;
				else B[i][j] = B[i][j - 1] + n;
				if (i == 0) A[i][j] = 0;
				else A[i][j] = A[i - 1][j];
			}
			else
			{
				if (i == 0) A[i][j] = n;
				else A[i][j] = A[i - 1][j] + n;
				if (j == 0) B[i][j] = 0;
				else B[i][j] = B[i][j - 1];
			}
		}
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/3114