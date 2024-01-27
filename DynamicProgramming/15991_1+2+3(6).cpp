#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000009;
int N, dp[100001], T;

int solve(int n)
{
	if (n == 0 || n == 1) return 1;
	int& ret = dp[n];
	if (ret >= 0) return ret;
	ret = 0;
	if (n == 2 || n == 3) ++ret;
	if (n >= 2) ret = (ret + solve(n - 2)) % MOD;
	if (n >= 4) ret = (ret + solve(n - 4)) % MOD;
	if (n >= 6) ret = (ret + solve(n - 6)) % MOD;
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

// https://www.acmicpc.net/problem/15991