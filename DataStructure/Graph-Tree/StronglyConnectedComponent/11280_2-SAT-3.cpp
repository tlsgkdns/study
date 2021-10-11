#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int N, M, vtxCnt = 0, sccCnt = 0;
vector<vector<int>> adj;
vector<int> sccId, discovered;
stack<int> st;
int getOpposite(int n)
{
	return n > N ? (n - N) : (n + N);
}
int dfs(int here)
{
	int ret = discovered[here] = vtxCnt++;
	st.push(here);
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (discovered[there] == -1)
			ret = min(ret, dfs(there));
		else if (sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}
	if (ret == discovered[here])
	{
		while (true)
		{
			int t = st.top();
			st.pop();
			sccId[t] = sccCnt;
			if (t == here) break;
		}
		++sccCnt;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	adj.resize(2 * N + 1); sccId.resize(2 * N + 1, -1);
	discovered.resize(2 * N + 1, -1);
	for (int m = 0; m < M; m++)
	{
		int i, j;
		cin >> i >> j;
		int l = (i < 0) ? N - i : i;
		int r = (j < 0) ? N - j : j;
		int revL = getOpposite(l);
		adj[getOpposite(l)].push_back(r);
		adj[getOpposite(r)].push_back(l);
	}
	for (int i = 1; i <= 2 * N; i++)
		if (discovered[i] == -1)
			dfs(i);
	int ans = 1;
	for (int i = 1; i <= N; i++)
		if (sccId[i] == sccId[i + N])
			ans = 0;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/11280