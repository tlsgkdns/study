#include <iostream>
#include <cstring>

using namespace std;
int N, K, dp[31][31];

int solve(int n, int k)
{
	if (k == 0 || k == n) return 1;
	int& ret = dp[n][k];
	if (ret >= 0) return ret;
	return ret = solve(n - 1, k - 1) + solve(n - 1, k);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	cout << solve(N - 1, K - 1) << '\n';
}

// https://www.acmicpc.net/problem/16395