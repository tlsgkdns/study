#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const double PI = 3.141592;
const ll MOD = 1000000000000000000;
ll dp[1001][1001], N;
ll solve(int n, int p)
{
	ll& ret = dp[n][p];
	if (ret >= 0) return ret;
	if (n - (p * PI) <= PI) return ret = 1;
	ret = solve(n - 1, p) + solve(n, p + 1);
	ret %= MOD;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	ll ans = solve(N, 0) % MOD;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1737