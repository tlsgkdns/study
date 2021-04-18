#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
vector<int> arr;
int n, ans = -1;
int solve(int pos, bool inc)
{
	int& ret = dp[pos][inc];
	if (ret != -1) return ret;
	for (int i = pos + 1; i < n; i++)
		if (inc && arr[pos] < arr[i])
			ret = max(ret, solve(i, true) + 1);
		else if (arr[pos] > arr[i])
			ret = max(ret, solve(i, false) + 1);
	if (ret == -1) ret = 0;
	return ret;
}
int main()
{
	cin >> n; arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dp.resize(n, vector<int>(2, -1));
	for (int i = 0; i < n; i++)
		for (int b = 0; b < 2; b++)
			ans = max(solve(i, b) + 1, ans);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11054