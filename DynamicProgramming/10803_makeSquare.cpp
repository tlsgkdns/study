#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
int n, m;
const int INF = numeric_limits<int>::max();
int solve(int w, int h)
{
	int& ret = dp[w][h];
	if (ret != INF) return ret;
	if (w >= h && w % h == 0) return ret = (w / h);
	if (h > w&& h% w == 0) return ret = (h / w);
	if (w >= h * 3) return ret = solve(w - h, h) + 1;
	for (int i = 1; i <= h / 2; i++) ret = min(ret, solve(w, h - i) + solve(w, i));
	for (int i = 1; i <= w / 2; i++) ret = min(ret, solve(w - i, h) + solve(i, h));
	return ret;
}
int main()
{
	cin >> n >> m;
	dp.resize(n + 1, vector<int>(m + 1, INF));
	cout << solve(n, m) << '\n';
}

// https://www.acmicpc.net/problem/10803