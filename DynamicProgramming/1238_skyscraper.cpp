#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
int N, L, R;
ll dp[101][101][101];

ll solve(int n, int l, int r)
{
	if (n == N) return (l == 0 && r == 0);
	ll& ret = dp[n][l][r];
	if (ret >= 0) return ret;
	ret = 0;
	if (l > 0) ret += solve(n + 1, l - 1, r);
	ret %= MOD;
	if (r > 0) ret += solve(n + 1, l, r - 1);
	ret %= MOD;
	ret += (n - 1) * solve(n + 1, l, r);
	ret %= MOD;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> R;
	memset(dp, -1, sizeof(dp));
	cout << solve(1, L - 1, R - 1) << '\n';
}

// https://www.acmicpc.net/problem/1328