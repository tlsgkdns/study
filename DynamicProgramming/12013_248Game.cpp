#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> dp[5001];
int N, arr[250], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[arr[i]].push_back({ i, 1 });
		ans = max(ans, arr[i]);
	}
	for (int idx = 1; idx < 5000; idx++)
	{
		if (dp[idx].empty()) continue;
		ans = max(ans, idx);
		for (int i = 0; i < dp[idx].size(); i++)
			for (int j = i + 1; j < dp[idx].size(); j++)
			{
				if (dp[idx][i].first + dp[idx][i].second == dp[idx][j].first)
					dp[idx + 1].push_back({ dp[idx][i].first, dp[idx][i].second + dp[idx][j].second });
				if (dp[idx][j].first + dp[idx][j].second == dp[idx][i].first)
					dp[idx + 1].push_back({ dp[idx][j].first, dp[idx][i].second + dp[idx][j].second });
			}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/12013