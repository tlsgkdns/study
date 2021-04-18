#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;
const int INF = 1000000;
int solve(int n)
{
	int& ret = dp[n];

	if (ret != INF) return ret;
	if (n == 1) return 0;
	if (n % 3 == 0)
		dp[n] = min(dp[n], solve(n / 3) + 1);
	if (n % 2 == 0)
		dp[n] = min(dp[n], solve(n / 2) + 1);
	dp[n] = min(dp[n], solve(n - 1) + 1);
	return dp[n];
}
void construct(int n)
{
	cout << n << " ";
	if (n == 1) return;
	if (n % 3 == 0 && dp[n] == dp[n / 3] + 1)
	{
		construct(n / 3);
		return;
	}
	if (n % 2 == 0 && dp[n] == dp[n / 2] + 1)
	{
		construct(n / 2);
		return;
	}
	construct(n - 1);
}
int main()
{
	int n;
	cin >> n; dp.resize(n + 1, INF);
	dp[1] = 0;
	cout << solve(n) << '\n';
	construct(n);
	cout << '\n';
}

// https://www.acmicpc.net/problem/12852