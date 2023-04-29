#include <iostream>
#include <cstring>
using namespace std;

int N, dp[1000001], T;
int solve(int n)
{
	if (n == 0) return 1;
	int& ret = dp[n];
	if (ret >= 0) return ret;
	ret = 0;
	if (n >= 3) ret += solve(n - 3);
	ret %= 1000000009;
	if (n >= 2) ret += solve(n - 2);
	ret %= 1000000009;
	if (n >= 1) ret += solve(n - 1);
	ret %= 1000000009;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << solve(N) << '\n';
	}
}

// https://www.acmicpc.net/problem/15988