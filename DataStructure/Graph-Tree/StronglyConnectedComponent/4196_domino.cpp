#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<vector<int>> adj, sccAdj;
vector<int> sccId, discovered;
vector<bool> visited;
stack<int> st;
int sccCnt = 0, vtxCnt = 0;

int dfs(int x)
{
	int ret = discovered[x] = vtxCnt++;
	st.push(x);
	for (int i = 0; i < adj[x].size(); i++)
	{
		int there = adj[x][i];
		if (discovered[there] == -1)
			ret = min(ret, dfs(there));
		else if (sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}
	if (ret == discovered[x])
	{
		while (true)
		{
			int t = st.top();
			st.pop();
			sccId[t] = sccCnt;
			if (t == x) break;
		}
		++sccCnt;
	}
	return ret;
}
int main()
{
	vector<int> ans;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, M, x, y;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int a = 0;
		sccCnt = vtxCnt = 0;
		cin >> N >> M;
		adj = vector<vector<int>>(N + 1);
		sccId = vector<int>(N + 1, -1);
		discovered = vector<int>(N + 1, -1);
		visited = vector<bool>(N + 1, false);
		for (int i = 0; i < M; i++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int i = 1; i <= N; i++)
			if (discovered[i] == -1)
				dfs(i);
		vector<int> indegree(sccCnt, 0);
		for (int i = 1; i <= N; i++)
			for (int j = 0; j < adj[i].size(); j++)
				if (sccId[i] != sccId[adj[i][j]])
					indegree[sccId[adj[i][j]]]++;
		for (int n = 0; n < sccCnt; n++)
			if (indegree[n] == 0) a++;
		ans.push_back(a);
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/4196

/*
Learned SCC + topologicalSort and method of calculating indegree.
*/