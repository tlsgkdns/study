#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000;
int N, dp[101][101][101][2];

int solve(int idx, int u, int d, bool dir)
{
	if (idx == N) return 1;
	int& ret = dp[idx][u][d][dir];
	if (ret >= 0) return ret;
	ret = 0;
	if (dir)
		for (int i = 0; i < u; i++)
			ret = (ret + solve(idx + 1, u - i - 1, d + i, false)) % MOD;
	else
		for (int i = 0; i < d; i++)
			ret = (ret + solve(idx + 1, u + i, d - i - 1, true)) % MOD;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	int ans = (N == 1) ? 1 : 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;
			if (i < j)
			{
				ans += solve(2, N - j, j - 2, false);
				ans %= MOD;
			}
			else
			{
				ans += solve(2, N - j - 1, j - 1, true);
				ans %= MOD;
			}
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1146