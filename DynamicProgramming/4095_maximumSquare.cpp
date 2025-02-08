#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001], N, M, A;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		int ans = 0;
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
			{
				cin >> A;
				if (A == 0) dp[i][j] = 0;
				else
				{
					dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
					ans = max(ans, dp[i][j]);
				}
			}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/4095