#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000000;
int dp[201][201];
int N, K;
int solve(int n, int k)
{
	if (k == 0)
	{
		if (n == 0) return 1;
		return 0;
	}
	int& ret = dp[n][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= n; i++)
	{
		ret += solve(n - i, k - 1);
		ret %= MOD;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	cout << solve(N, K) << '\n';
}

// https://www.acmicpc.net/problem/2225