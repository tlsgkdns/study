#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
int S, D, K, H, dp[51][51][51][51];

int solve(int idx, int d, int k, int h)
{
	if (idx < 0 || d < 0 || k < 0 || h < 0) return 0;
	if (idx == 0) return (d == 0 && k == 0 && h == 0);
	int& ret = dp[idx][d][k][h];
	if (ret >= 0) return ret;
	ret = solve(idx - 1, d - 1, k, h); ret %= MOD;
	ret += solve(idx - 1, d, k - 1, h); ret %= MOD;
	ret += solve(idx - 1, d, k, h - 1); ret %= MOD;
	ret += solve(idx - 1, d - 1, k - 1, h); ret %= MOD;
	ret += solve(idx - 1, d - 1, k, h - 1); ret %= MOD;
	ret += solve(idx - 1, d, k - 1, h - 1); ret %= MOD;
	ret += solve(idx - 1, d - 1, k - 1, h - 1); ret %= MOD;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> S >> D >> K >> H;
	cout << solve(S, D, K, H) << '\n';
}

// https://www.acmicpc.net/problem/12996