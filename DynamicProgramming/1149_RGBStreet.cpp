#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int house[1001][3];
int dp[1001][3];
int n, ans = numeric_limits<int>::max();
int solve(int prev, int pos)
{
	if (pos == n) return 0;
	int& ret = dp[pos][prev];
	if (ret != -1) return ret;
	ret = numeric_limits<int>::max();
	for (int i = 0; i < 3; i++)
	{
		if (prev == i) continue;
		ret = min(ret, solve(i, pos + 1) + house[pos][i]);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	for (int i = 0; i < 3; i++)
		ans = min(ans, solve(i, 1) + house[0][i]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1149