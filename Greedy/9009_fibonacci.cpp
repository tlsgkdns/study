#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> dp;
int N, T;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	dp.push_back(0); dp.push_back(1);
	for (int i = 2; i <= 45; i++) dp.push_back(dp[i - 1] + dp[i - 2]);
	cin >> T;
	while (T--)
	{
		vector<int> ans;
		cin >> N;
		while (N > 0)
		{
			auto iter = lower_bound(dp.begin(), dp.end(), N);
			if (*iter != N) --iter;
			ans.push_back(*iter);
			N -= *iter;
		}
		for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/9009