#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1000000000;
int N, dp[1000001], ans = 0;

int solve(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	int& ret = dp[n];
	if (ret < MOD) return ret;
	ret = (solve(n - 1) + solve(n - 2)) % MOD;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i <= abs(N); i++) dp[i] = MOD + 1;
	ans = solve(abs(N));
	if (N < 0 && N % 2 == 0) cout << -1 << '\n';
	else if (N == 0) cout << 0 << '\n';
	else cout << 1 << '\n';
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1788