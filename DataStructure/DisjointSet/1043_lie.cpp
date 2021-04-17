#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> know;

struct dset
{
	vector<int> parent;
	vector<int> rank;
	int n;

	dset(int l)
	{
		n = l + 1;
		parent.resize(n); rank.resize(n, 1);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u)
	{
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v)
	{
		if (u != 0 && rank[u] < rank[v]) merge(v, u);

		int f1 = find(u); int f2 = find(v);
		parent[f2] = f1;
		if (rank[f1] == rank[f2]) rank[f1]++;
	}
};
int main()
{
	int n, m, k, ans = 0;
	cin >> n >> m;
	cin >> k;
	know.resize(n + 1, false);
	dset p(n);
	vector<vector<int>> party(m);
	for (int i = 0; i < k; i++)
	{
		int e; cin >> e;
		know[e] = true;
	}
	for (int i = 0; i < m; i++)
	{
		int a, f = -1; cin >> a;
		for (int j = 0; j < a; j++)
		{
			int e; cin >> e;
			if (f == -1) f = e;
			p.merge(e, f);
			party[i].push_back(e);
		}
	}
	for (int i = 1; i <= n; i++)
		if (know[i]) p.merge(0, i);
	for (vector<int> pr : party)
		if (p.find(pr[0]) != 0) ans++;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1043