#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100001;
int dp[MAX], N;
int solve(int n)
{
	if (n == 0) return 0;
	int& ret = dp[n];
	if (ret >= 0) return ret;
	ret = MAX;
	for (int i = 1; i * i <= n; i++)
		ret = min(ret, solve(n - (i * i)) + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << solve(N) << '\n';
}

// https://www.acmicpc.net/problem/1699