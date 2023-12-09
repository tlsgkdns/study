#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
int N, L;
ll dp[301][301];
const ll MOD = 100030001;
ll solve(int n, int h)
{
	if (n == 0) return 1;
	if (h == 0) return 0;
	ll& ret = dp[n][h];
	if (ret >= 0) return ret;
	if (n == 0 && h == 0) return ret = 0;
	ret = 0;
	for (int i = 0; i < n; i++)
	{
		ret += solve(i, h - 1) * solve(n - 1 - i, h - 1);
		ret %= MOD;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1L, sizeof(dp));
	cin >> N >> L;
	cout << (solve(N, L) - solve(N, L - 1) + MOD) % MOD << '\n';
}

// https://www.acmicpc.net/problem/16468