#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

const int INF = 1000000000;
int n, ans = INF;
vector<vector<int>> w, dp;
int solve(bitset<16> past, int pos)
{
	int& ret = dp[past.to_ulong()][pos];
	if (past.count() == n) return ret = w[pos][0];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < n; i++)
	{
		if (past.test(i) || w[pos][i] == INF) continue;
		past.set(i);
		ret = min(ret, solve(past, i) + w[pos][i]);
		past.reset(i);
	}
	return ret;
}
int main()
{
	cin >> n;
	w.resize(n, vector<int>(n));
	dp.resize(1 << n, vector<int>(n, -1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> w[i][j];
			if (w[i][j] == 0) w[i][j] = INF;
		}
	bitset<16> b(0); b.set(0);
	cout << solve(b, 0) << '\n';
}

// https://www.acmicpc.net/problem/2098