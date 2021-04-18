#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> value;
vector<int> weight;
vector<vector<int>> dp;

int main()
{
	int n, k;
	cin >> n >> k;
	value.resize(n + 1);
	weight.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> weight[i] >> value[i];
	dp.resize(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			if (j >= weight[i])
				dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);
			else
				dp[i][j] = dp[i - 1][j];
	cout << dp[n][k] << endl;
}

// https://www.acmicpc.net/problem/12865