#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> ans;
int N, T;
ll dp[101];
ll solve(int n)
{
	if (n <= 0) return 0;
	ll& ret = dp[n];
	if (ret >= 0) return ret;
	return ret = solve(n - 1) + solve(n - 5);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0; dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2;
	cin >> T;
	while (T--)
	{
		cin >> N;
		ans.push_back(solve(N));
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/9461