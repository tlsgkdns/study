#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[101][10001];
vector<int> cost, memory;
int n, m;
int main()
{
	cin >> n >> m;
	cost.resize(n + 1); memory.resize(n + 1);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)	cin >> memory[i];
	for (int i = 1; i <= n; i++)	cin >> cost[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 10000; j++)
			if (j >= cost[i])
				dp[i][j] = max(dp[i - 1][j], memory[i] + dp[i - 1][j - cost[i]]);
			else
				dp[i][j] = dp[i - 1][j];
	int ans = 1;
	for (ans = 1; ans <= 10001; ans++) if (dp[n][ans] >= m) break;
	cout << ans << '\n';
}

//https://www.acmicpc.net/problem/7579

/*
Harder than I expected.
I need to more learn about knapsack problem.
*/