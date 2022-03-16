#include <iostream>
#include <cstring>
using namespace std;

int dp[1001][1001];
int N, K;

int solve(int n, int k)
{
	if (n == k || k == 0) return 1;
	int& ret = dp[n][k];
	if (ret != -1) return ret;
	return ret = (solve(n - 1, k - 1) + solve(n - 1, k)) % 10007;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	cout << solve(N, K) << '\n';
}

// https://www.acmicpc.net/problem/11051