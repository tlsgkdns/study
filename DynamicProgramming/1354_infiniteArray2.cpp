#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
ll N, P, Q, X, Y;
unordered_map<ll, ll> dp;

ll solve(ll a)
{
	if (a <= 0) return 1;
	if (dp.count(a) > 0) return dp[a];
	ll& ret = dp[a];
	ret = solve((a / P) - X) + solve((a / Q) - Y);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P >> Q >> X >> Y;
	cout << solve(N) << '\n';
}

// https://www.acmicpc.net/problem/1354