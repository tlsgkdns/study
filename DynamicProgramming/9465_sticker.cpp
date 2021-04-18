#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> ans;
	int n, t;
	cin >> t;
	for (int e = 0; e < t; e++)
	{
		cin >> n;
		vector<vector<int>> dp(3, vector<int>(n + 1, -1));
		vector<vector<int>> stick(2, vector<int>(n + 1));
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				cin >> stick[i][j];
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				dp[0][0] = stick[0][0];
				dp[1][0] = stick[1][0];
				dp[2][0] = 0;
				continue;
			}
			dp[0][i] = max(dp[1][i - 1] + stick[0][i], dp[2][i - 1] + stick[0][i]);
			dp[1][i] = max(dp[0][i - 1] + stick[1][i], dp[2][i - 1] + stick[1][i]);
			dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]);
		}
		dp;
		int a = max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1]));
		ans.push_back(a);
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/9465