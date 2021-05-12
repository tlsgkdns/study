#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> tri, dp;
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n; tri.resize(n, vector<int>(n));
	dp.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> tri[i][j];
	for (int i = 0; i < n; i++)
		dp[n - 1][i] = tri[n - 1][i];
	for (int i = n - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			dp[i][j] = tri[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
	cout << dp[0][0] << '\n';
}

// https://www.acmicpc.net/problem/1932