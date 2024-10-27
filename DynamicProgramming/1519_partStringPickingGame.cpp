#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int N, dp[1000001], dp2[1000001];

int solve(int n)
{
	if (n < 10) return dp[n] = 0;
	int& ret = dp[n];
	if (ret >= 0) return ret;
	vector<int> num;
	string now = to_string(n);
	for (int i = 0; i < now.size(); i++)
		for (int j = i + 1; j <= now.size(); j++)
		{
			if (now[i] == '0') continue;
			num.push_back(stoi(string(now.begin() + i, now.begin() + j)));
		}
	sort(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++)
		if (num[i] > 0 && num[i] != n)
		{
			int nxt = solve(n - num[i]) + 1;
			if (nxt % 2 > 0)
			{
				ret = nxt;
				dp2[n] = num[i];
				return ret;
			}
		}
	return ret = 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	solve(N);
	if (dp[N] % 2 == 0) cout << -1 << '\n';
	else cout << dp2[N] << '\n';
}

// https://www.acmicpc.net/problem/1519