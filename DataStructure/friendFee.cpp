#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000001

using namespace std;

int n, m, k;
vector<int> cost;

struct Dset
{
	vector<int> parent;
	vector<int> rank;

	void resize(int num)
	{
		parent.resize(num + 1);
		rank.resize(num + 1, 1);
		for (int i = 1; i <= num; i++)
			parent[i] = i;
	}
	int find(int u)
	{
		if (u == parent[u]) return u;

		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v)
	{
		if (rank[u] < rank[v]) merge(v, u);

		int p1 = find(u);
		int p2 = find(v);

		if (p1 == p2) return;

		parent[p2] = p1;
		if (rank[p1] == rank[p2])
			rank[p1]++;
	}
};
Dset d;

int main()
{
	int a, b;
	cin >> n >> m >> k;
	cost.resize(n + 1);
	vector<int> mn(n + 1, INF);
	d.resize(n);

	for (int i = 1; i <= n; i++)
		cin >> cost[i];


	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		d.merge(a, b);
	}


	for (int i = 1; i <= n; i++)
	{
		int id = d.find(i);
		mn[id] = min(mn[id], cost[i]);
	}
	int money = 0;
	for (int e : mn)
	{
		if (e == INF) continue;
		money += e;
	}

	if (money > k) cout << "Oh no" << '\n';
	else cout << money << '\n';
}

// https://www.acmicpc.net/problem/16562

/*
disjoint set problem.
Calculate most minimum cost to connect that group;
Not DFS.
*/