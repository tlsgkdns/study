#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using pi = pair<int, int>;
const int MAX = 100001;
vector<vector<int>> graph, dp;
vector<int> depth, ans;
int N, M, a, b, maxLevel;
void getTree(int here, int parent)
{
	depth[here] = depth[parent] + 1;
	dp[here][0] = parent;
	for (int i = 1; i <= maxLevel; i++)
		dp[here][i] = dp[dp[here][i - 1]][i - 1];
	for (int i = 0; i < graph[here].size(); i++)
		if (graph[here][i] != parent)
			getTree(graph[here][i], here);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	maxLevel = (int)floor(log2(MAX));
	graph.resize(N + 1); dp.resize(N + 1, vector<int>(20));
	depth.resize(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	depth[0] = depth[1] = -1;
	getTree(1, 0);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		if (depth[a] != depth[b])
		{
			if (depth[a] > depth[b]) swap(a, b);
			for (int i = maxLevel; i >= 0; i--)
				if (depth[a] <= depth[dp[b][i]])
					b = dp[b][i];
		}
		int lca = a;
		if (a != b)
		{
			for (int i = maxLevel; i >= 0; i--)
			{
				if (dp[a][i] != dp[b][i])
				{
					a = dp[a][i];
					b = dp[b][i];
				}
				lca = dp[a][i];
			}
		}
		ans.push_back(lca);
	}
	for (int a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/11438