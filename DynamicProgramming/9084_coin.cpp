#include <iostream>
#include <cstring>
using namespace std;

int dp[21][10001], T, N, M, coin[21];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; i++) cin >> coin[i];
		cin >> M;
		for (int i = 0; i < N; i++)
		{
			if (i == 0)
			{
				for (int j = coin[i]; j <= M; j += coin[i])
					dp[i][j] = 1;
				dp[i][0] = 1;
			}

			else
			{
				for (int j = 0; j <= M; j++)
				{
					if (j >= coin[i])
						dp[i][j] = dp[i][j - coin[i]] + dp[i - 1][j];
					else
						dp[i][j] = dp[i - 1][j];
				}
			}
		}
		cout << dp[N - 1][M] << '\n';
	}
}


// https://www.acmicpc.net/problem/9084