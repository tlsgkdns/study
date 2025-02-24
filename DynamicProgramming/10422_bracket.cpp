#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;
const int MOD = 1000000007;
int N, T;
ll dp[5001];
ll solve(int idx)
{

	if (idx <= 0) return 1;
	ll& ret = dp[idx];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = 2; i <= idx; i++)
	{
		ret += solve(i - 2) * solve(idx - i);
		ret %= MOD;
	}
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
		cin >> N;
		cout << solve(N) << '\n';
	}
}

// https://www.acmicpc.net/problem/10422