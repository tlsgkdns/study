#include <iostream>
#include <cstring>

using namespace std;
int N, T, dp[100][100][15];

int solve(int y, int x, int c)
{
	if (c == 0) return (y == 0 && x == 0);
	int& ret = dp[y + 50][x + 50][c];
	if (ret >= 0) return ret;
	return ret = solve(y - 1, x - 2, c - 1) + solve(y - 2, x, c - 1) + solve(y - 1, x + 2, c - 1)
		+ solve(y + 1, x - 2, c - 1) + solve(y + 1, x + 2, c - 1) + solve(y + 2, x, c - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << solve(0, 0, N) << '\n';
	}
}

// https://www.acmicpc.net/problem/5069