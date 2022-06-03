#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
ll dp[100001][2];
ll diff1[100001], diff2[100001];
int N;
ll solve(int idx, bool prev)
{
	if (idx == N) return 1;
	ll& ret = dp[idx][prev];
	if (ret != -1) return ret;
	ll tmp = 0;
	if (!prev)
	{
		if (idx >= 1) tmp = solve(idx + 1, false) * diff2[idx - 1] % MOD;
		ret = tmp + (solve(idx + 1, true) * diff2[idx]) % MOD + (solve(idx + 1, false) * diff1[idx]) % MOD;
	}
	else
	{
		if (diff2[idx - 1] > 1) tmp = (solve(idx + 1, false) * (diff2[idx - 1] - 1)) % MOD;
		ret = tmp + (solve(idx + 1, true) * diff2[idx]) % MOD + (solve(idx + 1, false) * diff1[idx]) % MOD;
	}
	return ret % MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> diff1[i];
	for (int i = 0; i < N - 1; i++) cin >> diff2[i];
	cout << solve(0, false) << '\n';
}

// https://www.acmicpc.net/problem/2854