#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> age, nameToIdx, idxToName, anss, dp;

int INF = 101;
int N, M, l, x, y, a, b, e;
char cmd;
int dfs(int here)
{
	if (dp[here] != INF) return dp[here];
	int ret = age[idxToName[here]];
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		ret = min(dfs(there), ret);
	}
	dp[here] = ret;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> l;
	age.resize(N + 1); adj.resize(N + 1);
	nameToIdx.resize(N + 1); idxToName.resize(N + 1);
	dp.resize(N + 1, INF);
	for (int i = 1; i <= N; i++)
	{
		cin >> age[i];
		nameToIdx[i] = i; idxToName[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		adj[y].push_back(x);
	}
	for (int i = 0; i < l; i++)
	{
		cin >> cmd;
		if (cmd == 'P')
		{
			cin >> e;
			int ans = INF;
			for (int i = 0; i < adj[nameToIdx[e]].size(); i++)
				ans = min(ans, dfs(adj[nameToIdx[e]][i]));
			anss.push_back(ans);
		}
		else
		{
			cin >> a >> b;
			dp = vector<int>(N + 1, INF);
			swap(nameToIdx[a], nameToIdx[b]);
			idxToName[nameToIdx[a]] = a;
			idxToName[nameToIdx[b]] = b;
		}
	}
	for (int an : anss)
	{
		if (an == INF) cout << "*\n";
		else cout << an << '\n';
	}
}

// https://www.acmicpc.net/problem/13625