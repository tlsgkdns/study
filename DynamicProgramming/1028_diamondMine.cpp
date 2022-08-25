#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 751;
char dia[MAX][MAX];
int R, C, dp[MAX][MAX][2], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> dia[i][j];
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (i == 0)
			{
				dp[i][j][0] = (dia[i][j] == '1');
				dp[i][j][1] = (dia[i][j] == '1');
			}
			else
			{
				if (dia[i][j] == '0')
				{
					dp[i][j][0] = 0;
					dp[i][j][1] = 0;
				}
				else
				{
					if (j > 0) dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
					else dp[i][j][0] = 1;
					if (j < C - 1) dp[i][j][1] = dp[i - 1][j + 1][1] + (dia[i][j] == '1');
					else dp[i][j][1] = 1;
				}

			}
		}
	for (int r = R - 1; r >= 0; r--)
		for (int c = C - 1; c >= 0; c--)
		{
			for (int l = min(dp[r][c][0], dp[r][c][1]); l > ans; l--)
			{
				if (dp[r - (l - 1)][c - (l - 1)][1] >= l && dp[r - (l - 1)][c + (l - 1)][0] >= l)
					ans = l;
			}
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1028