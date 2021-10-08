#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K, L, cnt = 0;
char c;
vector<int> parent, ls, rs, order, ord;
vector<vector<int>> adj;
vector<char> ops;
vector<bool> v;
bool ans = true;
int find(int a)
{
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	int p = find(a);
	int q = find(b);
	if (p < q) swap(p, q);
	parent[p] = q;
}
void dfs(int here)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		dfs(there);
	}
	order.push_back(here);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	parent.resize(N); adj.resize(N);
	v.resize(N, false);
	for (int i = 0; i < N; i++)	parent[i] = i;
	for (int i = 0; i < M; i++)
	{
		cin >> K >> c >> L;
		if (c == '=')
		{
			merge(K, L);
			continue;
		}
		ls.push_back(K);
		ops.push_back(c);
		rs.push_back(L);
	}
	for (int i = 0; i < ops.size(); i++)
	{
		if (ops[i] == '<') adj[find(ls[i])].push_back(find(rs[i]));
		if (ops[i] == '>') adj[find(rs[i])].push_back(find(ls[i]));
	}
	for (int i = 0; i < N; i++)
	{
		if (v[find(i)]) continue;
		v[find(i)] = true;
		dfs(find(i));
	}
	reverse(order.begin(), order.end());
	ord.resize(N);
	for (int i = 0; i < order.size(); i++)
		ord[order[i]] = i;
	for (int i = 0; i < N; i++)
	{
		if (!ans) break;
		for (int j = 0; j < adj[i].size(); j++)
			if (ord[find(i)] >= ord[find(adj[i][j])])
			{
				ans = false;
				break;
			}
	}
	if (ans) cout << "consistent\n";
	else cout << "inconsistent\n";
}
// https://www.acmicpc.net/problem/13344