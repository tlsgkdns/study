#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj, dp;
vector<int> w, ans;
vector<bool> v;
int N, a, b;

void dfs(int here)
{
	dp[here][0] = 0;
	dp[here][1] = w[here];
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		dfs(there);
		dp[here][0] += max(dp[there][0], dp[there][1]);
		dp[here][1] += dp[there][0];
	}
}
void tracking(int here, bool sel)
{
	if (sel) ans.push_back(here);
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		if (!sel && dp[there][0] < dp[there][1])
			tracking(there, true);
		else
			tracking(there, false);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	adj.resize(N + 1); w.resize(N + 1);
	v.resize(N + 1, false);
	dp.resize(N + 1, vector<int>(2));
	for (int i = 1; i <= N; i++)
		cin >> w[i];
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	v[1] = true;
	dfs(1);
	v = vector<bool>(N + 1, false);
	v[1] = true;
	tracking(1, (dp[1][true] > dp[1][false]));
	sort(ans.begin(), ans.end());
	cout << max(dp[1][true], dp[1][false]) << '\n';
	for (int a : ans) cout << a << " ";
	cout << '\n';
}
// https://www.acmicpc.net/problem/2213