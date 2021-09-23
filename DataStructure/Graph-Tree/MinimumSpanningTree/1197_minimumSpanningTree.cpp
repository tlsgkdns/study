#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g;
int find(int a)
{
	if (a == g[a]) return a;
	return g[a] = find(g[a]);
}
void merge(int p, int q)
{
	if (p > q) swap(p, q);
	int a = find(p), b = find(q);
	g[a] = b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<pair<int, pair<int, int>>> edges;
	int V, E, A, B, C;
	cin >> V >> E;
	g.resize(V + 1);
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		edges.push_back(make_pair(C, make_pair(A, B)));
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= V; i++) g[i] = i;
	int ans = 0;
	for (auto edge : edges)
	{
		if (find(edge.second.first) != find(edge.second.second))
		{
			ans += edge.first;
			merge(edge.second.first, edge.second.second);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1197