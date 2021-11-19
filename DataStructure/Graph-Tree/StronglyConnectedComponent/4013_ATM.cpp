#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> adj, sccAdj;
vector<int> discovered, sccId, atm, sccAtm, dp, indegree;
stack<int> st;
vector<bool> v;

int N, M, S, P, sccCnt = 0, nodeId = 0, ans = 0;

int dfs(int here)
{
	int ret = discovered[here] = nodeId++;
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
			sccAtm[sccCnt] += atm[t];
			if (t == here) break;
		}
		++sccCnt;
	}
	return ret;
}

void dfs2(int here)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (sccId[there] != -1 && sccId[here] != sccId[there])
		{
			sccAdj[sccId[here]].push_back(sccId[there]);
			indegree[sccId[there]]++;
		}
		if (v[there]) continue;
		v[there] = true;
		dfs2(there);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	adj.resize(N + 1); discovered.resize(N + 1, -1); atm.resize(N + 1, 0);
	sccAtm.resize(N + 1, 0); sccId.resize(N + 1, -1); v.resize(N + 1, false);
	int A, B, d;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
	}
	for (int i = 1; i <= N; i++) cin >> atm[i];
	cin >> S >> P;
	dfs(S);
	indegree.resize(sccCnt + 1, 0); sccAdj.resize(sccCnt + 1);
	dp.resize(sccCnt + 1, 0);
	dfs2(S);
	queue<int> q;
	q.push(sccId[S]);
	dp[sccId[S]] = sccAtm[sccId[S]];
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int there : sccAdj[here])
		{
			indegree[there]--;
			dp[there] = max(dp[here] + sccAtm[there], dp[there]);
			if (indegree[there] == 0)
				q.push(there);
		}
	}
	for (int i = 0; i < P; i++)
	{
		cin >> d;
		if (sccId[d] == -1) continue;
		ans = max(ans, dp[sccId[d]]);
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/4013