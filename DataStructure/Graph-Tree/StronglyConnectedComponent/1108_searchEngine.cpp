#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;
const int MAX = 2501;
stack<int> st;
unordered_map<string, int> um;
int N, cnt = 0, L, indegree[MAX], v[MAX], vcnt = 0, ssc[MAX], sscCnt = 0;
vector<int> adj[MAX], adj2[MAX];
long long ans[MAX];
string S, D, Q;

int dfs(int here)
{
	int ret = v[here] = vcnt++;
	st.push(here);
	for (int there : adj[here])
	{

		if (v[there] < 0)
			ret = min(ret, dfs(there));
		else if (ssc[there] < 0)
			ret = min(ret, v[there]);
	}
	if (ret == v[here])
	{
		while (true)
		{
			int t = st.top();
			st.pop();
			ssc[t] = sscCnt;
			if (t == here) break;
		}
		++sscCnt;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	memset(ssc, -1, sizeof(ssc));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		cin >> L;
		if (um.find(S) == um.end()) um[S] = cnt++;
		int t = um[S];
		while (L--)
		{
			cin >> D;
			if (um.find(D) == um.end()) um[D] = cnt++;
			int f = um[D];
			adj[f].push_back(t);
		}
	}
	for (int i = 0; i < cnt; i++)
		if (v[i] < 0)
			dfs(i);
	queue<int> q;
	fill(ans, ans + MAX, 1);
	for (int here = 0; here < cnt; here++)
		for (int there : adj[here])
			if (ssc[here] != ssc[there])
			{
				indegree[there]++;
				adj2[here].push_back(there);
			}
	for (int i = 0; i < cnt; i++) if (indegree[i] == 0) q.push(i);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int& there : adj2[here])
		{
			ans[there] += ans[here];
			if (--indegree[there] == 0) q.push(there);
		}
	}
	cin >> Q;
	cout << ans[um[Q]] << '\n';
}

// https://www.acmicpc.net/problem/1108