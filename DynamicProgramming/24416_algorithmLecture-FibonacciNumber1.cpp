#include <iostream>
#include <cstring>
using namespace std;
int dp[41], N;

int solve(int n)
{
	if (n <= 2) return 1;
	int& ret = dp[n];
	if (ret >= 0) return ret;
	ret = solve(n - 1) + solve(n - 2);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << solve(N) << " " << N - 2 << '\n';
}

// https://www.acmicpc.net/problem/24416