#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<list<pair<int, int>>> tree;
vector<bool> v;
long long dfs(int s)
{
	long long m = 0;
	for (auto t : tree[s])
	{
		int nxt = t.first;
		int l = t.second;
		if (v[nxt]) continue;
		v[nxt] = true;
		m = max(m, dfs(nxt) + l);
	}
	return m;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, r = 0;
	cin >> n;
	tree.resize(n + 1); v.resize(n + 1, false);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		tree[a].push_back(make_pair(b, l));
		tree[b].push_back(make_pair(a, l));
	}
	for (int i = 1; i <= n; i++)
	{
		if (tree[i].size() != 1) continue;
		v[i] = true;
		r = max(r, dfs(i));
		v = vector<bool>(n + 1, false);
	}
	cout << r << '\n';
}

// https://www.acmicpc.net/problem/1967

/*
tree dfs practice problem
*/