#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
ll T, N, dp[65][11];

ll solve(int idx, int prv)
{
	if (idx == N) return 1;
	ll& ret = dp[idx][prv];
	if (ret >= 0) return ret;
	ret = 0;
	for (int n = prv; n <= 9; n++)
		ret += solve(idx + 1, n);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		memset(dp, -1, sizeof(dp));
		cout << solve(0, 0) << '\n';
	}
}

// https://www.acmicpc.net/problem/2688