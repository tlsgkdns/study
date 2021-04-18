#include <iostream>
#include <vector>

using namespace std;
vector<vector<bool>> dp;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n;
	vector<int> v(n + 1);
	dp.resize(n + 1, vector<bool>(n + 1, false));
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		dp[i][i] = true;
	}
	cin >> m;
	vector<pair<int, int>> q(m);
	for (int i = 0; i < m; i++) cin >> q[i].first >> q[i].second;
	for (int s = n; s > 0; s--)
		for (int e = 1; e <= n; e++)
		{
			if (s >= e) continue;
			if (dp[s + 1][e - 1] || (e - s == 1))
				dp[s][e] = (v[s] == v[e]);
		}

	for (auto p : q)
		cout << dp[p.first][p.second] << '\n';
}

// https://www.acmicpc.net/problem/10942