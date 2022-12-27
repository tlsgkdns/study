#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1001], N, P[1001];

int solve(int n)
{
	if (n == 0) return 0;
	int& ret = dp[n];
	if (ret >= 0) return ret;
	ret = 1000000001;
	for (int i = 1; i <= n; i++)
		ret = min(ret, solve(n - i) + P[i]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i];
	cout << solve(N) << '\n';
}

// https://www.acmicpc.net/problem/16194