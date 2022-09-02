#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;
using pii = pair<int, int>;
const int MAX = 1001;
vector<int> discovered, sccId, adj[MAX], sccAdj[MAX];
int sccSz[MAX], indegree[MAX], dp[MAX][MAX];
stack<int> S;
int sccCnt = 0, vtxCnt = 0, N, K, X, ans = 0;
bool v[MAX];
vector<pii> cnt;
int dfs(int here)
{
	int ret = discovered[here] = vtxCnt++;
	S.push(here);
	for (int there : adj[here])
	{
		if (discovered[there] == -1) ret = min(ret, dfs(there));
		else if (sccId[there] == -1) ret = min(ret, discovered[there]);
	}
	if (ret == discovered[here])
	{
		while (true)
		{
			int t = S.top();
			S.pop();
			sccId[t] = sccCnt;
			sccSz[sccCnt]++;
			if (t == here) break;
		}
		++sccCnt;
	}
	return ret;
}

int dfs2(int here)
{
	int ret = sccSz[here];
	for (int there : sccAdj[here])
	{
		if (v[there]) continue;
		v[there] = true;
		ret += dfs2(there);
	}
	return ret;
}
int solve(int idx, int s)
{
	if (cnt.size() <= idx) return 0;
	int& ret = dp[idx][s];
	if (ret >= 0) return ret;
	ret = max(ret, solve(idx + 1, s));
	for (int w = cnt[idx].first; w <= cnt[idx].second; w++)
	{
		if (s < w) break;
		ret = max(ret, solve(idx + 1, s - w) + w);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, false, sizeof(v)); memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	discovered.resize(N + 1, -1); sccId.resize(N + 1, -1);
	for (int i = 1; i <= N; i++)
	{
		cin >> X;
		adj[X].push_back(i);
	}
	for (int i = 1; i <= N; i++)
		if (discovered[i] == -1)
			dfs(i);
	for (int i = 1; i <= N; i++)
		for (int e : adj[i])
			if (sccId[i] != sccId[e])
			{
				indegree[sccId[e]]++;
				sccAdj[sccId[i]].push_back(sccId[e]);
			}
	for (int i = 0; i < sccCnt; i++)
		if (indegree[i] == 0)
		{
			v[i] = true;
			cnt.push_back({ sccSz[i], dfs2(i) });
		}
	cout << solve(0, K) << '\n';
}

// https://www.acmicpc.net/problem/10265