#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> popu;
vector<bool> v;
vector<vector<int>> adj, dp;
int N, a, b;
void dfs(int here)
{
	dp[here][1] = popu[here];
	dp[here][0] = 0;

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	popu.resize(N + 1); adj.resize(N + 1);
	v.resize(N + 1, false); dp.resize(N + 1, vector<int>(2, false));
	for (int i = 1; i <= N; i++) cin >> popu[i];
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	v[1] = true;
	dfs(1);
	cout << max(dp[1][1], dp[1][0]) << '\n';
}

// https://www.acmicpc.net/problem/1949