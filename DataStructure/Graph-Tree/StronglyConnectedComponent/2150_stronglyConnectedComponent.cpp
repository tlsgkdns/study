#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> adj, ans;
stack<int> st;
vector<int> discovered, sccId;
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

bool cmp(vector<int>& v1, vector<int>& v2)
{
	return v1[0] < v2[0];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int v, e, a, b;
	cin >> v >> e;
	adj.resize(v + 1);

	for (int i = 0; i < e; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
	}
	sccId.resize(v + 1, -1);
	discovered.resize(v + 1, -1);
	ans.resize(v + 1);
	for (int i = 1; i <= v; i++) if (discovered[i] == -1) dfs(i);
	for (int i = 1; i <= v; i++)
		ans[sccId[i]].push_back(i);
	sort(ans.begin(), ans.begin() + sccCnt, cmp);
	cout << sccCnt << '\n';
	for (int i = 0; i < sccCnt; i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << -1 << '\n';
	}
}

// https://www.acmicpc.net/problem/2150