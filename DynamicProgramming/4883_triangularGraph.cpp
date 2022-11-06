#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
vector<ll> ans;
const ll INF = 1e15;
ll dp[100001][3], graph[100001][3], N;
ll dfs(int here, int idx)
{
	if (here == N - 1)
	{
		if (idx == 1) return graph[here][idx];
		else if (idx == 2) return INF;
	}
	ll& ret = dp[here][idx];
	if (dp[here][idx] < INF) return ret;
	if (here < N - 1)
		for (int i = 0; i < 3; i++)
		{
			if (abs(i - idx) >= 2) continue;
			ret = min(ret, dfs(here + 1, i) + graph[here][idx]);
		}
	if (idx < 2)
		ret = min(ret, dfs(here, idx + 1) + graph[here][idx]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 3; j++)
			{
				dp[i][j] = INF;
				cin >> graph[i][j];
			}
		ll a = dfs(0, 1);
		ans.push_back(a);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << i + 1 << ". " << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/4883