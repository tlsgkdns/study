#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
using ll = long long;
vector<int> adj[10] = { {7}, {2, 4}, {1, 3, 5}, {2, 6}, {1, 5, 7}, {2, 4, 6, 8}, {3, 5, 9}, {0, 4, 8}, {5, 7, 9}, {6, 8} };
int T, N;
ll dp[10][1001];
ll solve(int here, int l)
{
	if (l == 0) return 1;
	ll& ret = dp[here][l];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = 0; i < adj[here].size(); i++)
	{
		ret += solve(adj[here][i], l - 1);
		ret %= 1234567;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> T;
	while (T--)
	{
		cin >> N;
		ll ans = 0;
		for (int i = 0; i <= 9; i++)
		{
			ans += solve(i, N - 1);
			ans %= 1234567;
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/2780