#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 9901;
int N, dp[100001][3];
int solve(int idx, int state)
{
	if (idx == N) return 1;
	int& ret = dp[idx][state];
	if (ret != -1) return ret;
	if (state == 0)
		ret = (solve(idx + 1, 0) + solve(idx + 1, 1) + solve(idx + 1, 2)) % MOD;
	if (state == 1)
		ret = (solve(idx + 1, 0) + solve(idx + 1, 2)) % MOD;
	if (state == 2)
		ret = (solve(idx + 1, 0) + solve(idx + 1, 2)) % MOD;
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/1309