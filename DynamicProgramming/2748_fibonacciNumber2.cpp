#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;
int N;
ll dp[100];
ll solve(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (dp[n] >= 0) return dp[n];
	return dp[n] = solve(n - 1) + solve(n - 2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << solve(N) << '\n';
}

// https://www.acmicpc.net/problem/2748