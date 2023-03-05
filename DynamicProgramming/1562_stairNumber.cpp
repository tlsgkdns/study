#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int MOD = 1e9;
ll dp[101][10][1030], N;
int a = (1 << 10) - 1;
ll solve(int idx, int prev, int v)
{
	if (idx == N)
	{
		if (v == a) return 1;
		return 0;
	}
	ll& ret = dp[idx][prev][v];
	if (ret >= 0) return ret;
	ret = 0;
	if (prev < 9) ret += solve(idx + 1, prev + 1, v | (1 << (prev + 1)));
	if (prev > 0) ret += solve(idx + 1, prev - 1, v | (1 << (prev - 1)));
	ret %= MOD;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= 9; i++)
	{
		ans += solve(1, i, (1 << i));
		ans %= MOD;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1562