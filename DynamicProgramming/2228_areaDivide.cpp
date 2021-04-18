#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = -1000000000;
vector<vector<vector<int>>> dp;
vector<int> arr;
int n, m;
int solve(int ptr, int part, bool flag)
{
	if (part == m) return 0;
	if (ptr == n)
	{
		if (part == m - 1 && flag) return 0;
		else return INF;
	}
	int& ret = dp[ptr][part][flag];
	if (ret != INF - 1) return ret;

	if (flag)
		ret = max(solve(ptr + 1, part + 1, false), solve(ptr + 1, part, true) + arr[ptr]);
	else
		ret = max(solve(ptr + 1, part, false), solve(ptr + 1, part, true) + arr[ptr]);

	return ret;
}
int main()
{
	cin >> n >> m; arr.resize(n);
	dp.resize(n, vector<vector<int>>(m, vector<int>(2, INF - 1)));
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << solve(0, 0, false) << '\n';
}

// https://www.acmicpc.net/problem/2228