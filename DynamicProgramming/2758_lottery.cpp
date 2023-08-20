#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
using ll = long long;
int T, N, M;
ll dp[2002][12];
ll solve(int here, int l)
{
	if (l == 1) return 1;
	ll& ret = dp[here][l];
	if (ret >= 0) return ret;
	ret = 0;
	for (int there = here / 2; there >= 1; there--)
		ret += solve(there, l - 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	memset(dp, -1, sizeof(dp));
	while (T--)
	{
		cin >> N >> M;
		ll ans = 0;
		for (int i = M; i >= 1; i--) ans += solve(i, N);
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/2758