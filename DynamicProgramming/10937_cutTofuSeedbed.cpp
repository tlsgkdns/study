#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int price[4][4] = { {100, 70, 40, 0}, {70, 50, 30, 0},
				{40, 30, 20, 0}, {0, 0, 0, 0} };
int grid[11][11];
int N, dp[11 * 11][1 << 11];
char ch;
int solve(int idx, int w)
{
	if (idx >= N * N) return 0;
	int& ret = dp[idx][w];
	if (ret >= 0) return ret;
	ret = solve(idx + 1, ((w << 1) & (1 << N) - 1));
	int y = idx / N, x = idx % N;
	if (!(w & (1 << (N - 1))))
	{
		if (x < N - 1 && !(w & (1 << N - 2)))
			ret = max(ret, solve(idx + 2, (w << 2) & ((1 << N) - 1)) + price[grid[y][x]][grid[y][x + 1]]);
		if (y < N - 1)
			ret = max(ret, solve(idx + 1, ((w << 1) & ((1 << N) - 1)) + 1) + price[grid[y][x]][grid[y + 1][x]]);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			switch (ch)
			{
			case 'A':
				grid[i][j] = 0;
				break;
			case 'B':
				grid[i][j] = 1;
				break;
			case 'C':
				grid[i][j] = 2;
				break;
			default:
				grid[i][j] = 3;
			}
		}
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/10937