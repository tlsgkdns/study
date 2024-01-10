#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
int SX, SY, T, N, X, Y, EX, EY, ans = 0;
ll dp[402][402][201];
bool v[402][402];

bool inRange(int x, int y, int t)
{
	return abs(x) + abs(y) <= t;
}
ll solve(int x, int y, int t)
{
	if (!inRange(x, y, t) || v[x + 200][y + 200]) return 0;
	if (x == 0 && y == 0) return 1;
	ll& ret = dp[x + 200][y + 200][t];
	if (ret >= 0) return ret;
	ret = solve(x - 1, y, t - 1);
	ret = (ret + solve(x, y - 1, t - 1)) % MOD;
	ret = (ret + solve(x + 1, y, t - 1)) % MOD;
	ret = (ret + solve(x, y + 1, t - 1)) % MOD;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1L, sizeof(dp));
	cin >> SX >> SY;
	cin >> T;
	cin >> EX >> EY;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		if (inRange(X - EX, Y - EY, T))
			v[X - EX + 200][Y - EY + 200] = true;
	}
	cout << solve(SX - EX, SY - EY, T) << '\n';
}

// https://www.acmicpc.net/problem/15938