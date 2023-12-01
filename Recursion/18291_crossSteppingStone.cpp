#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
int T, N;
ll solve(ll a, ll b)
{
	if (b <= 0) return 1;
	if (b == 1) return a;
	ll ret = solve(a, (b / 2));
	ret *= ret;
	ret %= MOD;
	if (b % 2 > 0)
	{
		ret *= 2;
		ret %= MOD;
	}
	ret %= MOD;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << solve(2, N - 2) % MOD << '\n';
	}
}

// https://www.acmicpc.net/problem/18291