#include <iostream>
#include <cstring>

using namespace std;

int T, N, M, A[22], dp[22][10003];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; i++) cin >> A[i];
		cin >> M;
		for (int i = 0; i < N; i++)
		{
			++dp[i][A[i]];
			for (int j = 1; j <= M; j++)
				if (j >= A[i])
					dp[i][j] += dp[i][j - A[i]] + ((i > 0) ? dp[i - 1][j] : 0);
				else if (i > 0)
					dp[i][j] = dp[i - 1][j];
		}
		cout << dp[N - 1][M] << '\n';
	}
}

// https://www.acmicpc.net/problem/3067