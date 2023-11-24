#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
ll K, N, dp[140][65];

ll solve(int h, int t)
{
	if (h == 0) return 0;
	if (t == N) return 1;
	ll& ret = dp[h][t];
	if (ret >= 0) return ret;
	ret = solve(h + 1, t + 1) + solve(h - 1, t + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> K >> N;
	cout << solve(K, 0) << '\n';
}

// https://www.acmicpc.net/problem/13703