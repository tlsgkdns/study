#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int n, m = numeric_limits<int>::max();
vector<pair<ll, ll>> ms;
vector<vector<ll>> dp;

int solve(int l, int r)
{
	if (l == r) return 0;
	ll& ret = dp[l][r];
	if (ret != numeric_limits<ll>::max()) return ret;

	for (int k = l; k < r; k++)
		ret = min(ret, ms[l].first * ms[r].second * ms[k].second + solve(l, k) + solve(k + 1, r));
	return ret;
}
int main()
{
	cin >> n;
	dp.resize(n + 1, vector<ll>(n + 1, numeric_limits<ll>::max()));
	ms.resize(n);
	for (int i = 0; i < n; i++)
		cin >> ms[i].first >> ms[i].second;
	cout << solve(0, n - 1) << '\n';
}

// https://www.acmicpc.net/problem/11049

/*
Standard dynamic programming problem.
I learned from the college lecture.
*/