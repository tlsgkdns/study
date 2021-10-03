#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<int>& d, vector<bool>& c, int x)
{
	for (int i = 0; i < adj[x].size(); i++)
	{
		int t = adj[x][i];

		if (c[t]) continue;
		c[t] = true;
		if (d[t] == 0 || dfs(adj, d, c, d[t]))
		{
			d[t] = x;
			return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);  cin.tie(NULL);
	vector<int> ans;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int N, M, a, b, as = 0;
		cin >> N >> M;
		vector<int> d(1001, 0);
		vector<vector<int>> adj(1001);
		for (int j = 1; j <= M; j++)
		{
			cin >> a >> b;
			for (int k = a; k <= b; k++)
				adj[j].push_back(k);
		}
		for (int idx = 1; idx <= M; idx++)
		{
			vector<bool> c(1001, false);
			if (dfs(adj, d, c, idx)) as++;
		}
		ans.push_back(as);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
} 

// https://www.acmicpc.net/problem/9576