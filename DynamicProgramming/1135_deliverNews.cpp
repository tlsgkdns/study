#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> dp;

int N, parent;

int dfs(int here)
{
	vector<int> times;
	dp[here] = adj[here].size();
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		times.push_back(-(dfs(there) + 1));
	}
	sort(times.begin(), times.end());
	for (int i = 0; i < times.size(); i++)
		dp[here] = max(-times[i] + i, dp[here]);
	return dp[here];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	adj.resize(N); dp.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> parent;
		if (parent < 0) continue;
		adj[parent].push_back(i);
	}
	cout << dfs(0) << '\n';
}

// https://www.acmicpc.net/problem/1135