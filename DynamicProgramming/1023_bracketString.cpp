#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;
ll N, K, dp[53][53];
string ans = "";
ll solve2(ll n, ll a)
{
	ll& ret = dp[n][a];
	if (n == 0)
	{
		if (a == 0) return ret = 1;
		return ret = 0;
	}
	if (ret >= 0) return ret;
	ret = 0;
	if (a > 0) ret += solve2(n - 1, a - 1);
	ret += solve2(n - 1, a + 1);
	return ret;
}
void solve(ll n, ll a, ll r, bool f)
{
	if (n == 0) return;
	if (r == 0)
	{
		while (n--)
		{
			ans.push_back('(');
		}
		return;
	}
	if (a < 0) f = true;
	ll s = pow(2, n - 1) - ((!f) ? dp[n - 1][a + 1] : 0);
	if (s > r)
	{
		ans.push_back('(');
		solve(n - 1, a + 1, r, f);
	}
	else
	{
		ans.push_back(')');
		solve(n - 1, a - 1, r - s, f);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	solve2(N, 0);
	solve(N, 0, K, false);
	if (pow(2, N) - dp[N][0] < K + 1) cout << -1 << '\n';
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1023