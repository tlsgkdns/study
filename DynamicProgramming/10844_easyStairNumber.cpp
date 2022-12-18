#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000000;
int dp[101][10], ans, N;
int solve(int idx, int prv)
{
	if (prv < 0 || prv > 9) return 0;
	if (idx == N) return 1;
	int& ret = dp[idx][prv];
	if (ret >= 0) return ret;
	ret = (solve(idx + 1, prv - 1) + solve(idx + 1, prv + 1)) % MOD;
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= 9; i++)
	{
		ans += solve(1, i);
		ans %= MOD;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10844