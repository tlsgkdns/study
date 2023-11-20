#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
int N;
ll dp[32];
ll solve(int n)
{
	if (n <= 1) return 1;
	ll& ret = dp[n];
	if (ret >= 0) return ret;
	return ret = solve(n - 1) + solve(n - 2) * 2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1L, sizeof(dp));
	cin >> N;
	if (N % 2 > 0) cout << (solve(N) + solve((N - 1) / 2)) / 2 << '\n';
	else cout << (solve(N) + solve(N / 2) + solve(N / 2 - 1) * 2) / 2 << '\n';
}

// https://www.acmicpc.net/problem/1720