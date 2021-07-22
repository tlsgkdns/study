#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char c;
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	int n, m, ans = -1;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m)), dp(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			arr[i][j] = c - '0';
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || j == 0 || arr[i][j] == 0) dp[i][j] = arr[i][j];
			else
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
			ans = max(dp[i][j], ans);
		}
	dp;
	ans *= ans;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1915