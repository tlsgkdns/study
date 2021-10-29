#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> sccId, found;
stack<int> st;
int sccCnt = 0, vtxCnt = 0;

int N, M;
int dfs(int here)
{
	int ret = found[here] = vtxCnt++;
	st.push(here);
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (found[there] == -1)
			ret = min(ret, dfs(there));
		else if (sccId[there] == -1)
			ret = min(ret, found[there]);
	}
	if (ret == found[here])
	{
		while (true)
		{
			int t = st.top();
			st.pop();
			sccId[t] = sccCnt;
			if (t == here) break;
		}
		sccCnt++;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	vector<vector<int>> ans;
	for (int t = 0; t < T; t++)
	{
		int A, B;
		cin >> N >> M;
		adj = vector<vector<int>>(N);
		sccId = vector<int>(N, -1);
		found = vector<int>(N, -1);
		sccCnt = 0, vtxCnt = 0;
		for (int i = 0; i < M; i++)
		{
			cin >> A >> B;
			adj[A].push_back(B);
		}
		for (int i = 0; i < N; i++)
			if (found[i] == -1)
				dfs(i);
		vector<bool> indegree(sccCnt, false);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < adj[i].size(); j++)
				if (sccId[i] != sccId[adj[i][j]])
					indegree[sccId[adj[i][j]]] = true;
		int start = -1;
		bool confuse = false;
		vector<int> arr;
		for (int id = 0; id < sccCnt; id++)
		{
			if (indegree[id]) continue;
			if (start == -1) start = id;
			else
			{
				confuse = true;
				break;
			}
		}
		if (start == -1) confuse = true;
		if (!confuse)
			for (int i = 0; i < N; i++)
			{
				if (sccId[i] == start)
					arr.push_back(i);
			}
		ans.push_back(arr);
	}
	for (vector<int> a : ans)
		if (a.empty()) cout << "Confused\n\n";
		else
		{
			for (int e : a) cout << e << '\n';
			cout << '\n';
		}
}
// https://www.acmicpc.net/problem/3977