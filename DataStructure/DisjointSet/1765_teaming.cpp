#include <iostream>
#include <vector>

using namespace std;

vector<int> parent, indegree;
vector<vector<int>> adj;
vector<bool> group, v;
int N, M, P, Q, ans = 0;
int find(int u)
{
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u == v) return;
	if (u > v) swap(u, v);
	parent[u] = v;
}
void dfs(int here, int prev)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		if (prev != -1) merge(there, prev);
		dfs(there, here);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	char cmd;
	adj.resize(N + 1); parent.resize(N + 1);
	group.resize(N + 1, false); indegree.resize(N + 1, 0);
	v.resize(N + 1, false);
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 1; i <= M; i++)
	{
		cin >> cmd >> P >> Q;
		if (cmd == 'F') merge(P, Q);
		else
		{
			adj[P].push_back(Q);
			adj[Q].push_back(P);
			indegree[P]++;
			indegree[Q]++;
		}
	}
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 1 && !v[i])
		{
			v[i] = true;
			dfs(i, -1);
		}
	for (int i = 1; i <= N; i++)
	{
		int f = find(i);
		if (group[f]) continue;
		group[f] = true;
		ans++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1765