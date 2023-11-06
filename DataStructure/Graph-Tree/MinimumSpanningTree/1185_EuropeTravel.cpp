#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, pair<int, int>>> edge;
int P, N, parent[10001], C[10001], ans = 1000000007, S, E, L;
int find(int u)
{
	if (parent[u] == u) return u;
	return find(parent[u]);
}

void merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u > v) swap(u, v);
	parent[u] = v;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P;
	for (int i = 1; i <= N; i++)
	{
		cin >> C[i];
		ans = min(ans, C[i]);
		parent[i] = i;
	}
	for (int i = 0; i < P; i++)
	{
		cin >> S >> E >> L;
		edge.push_back({ 2 * L + C[S] + C[E], {S, E} });
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < P; i++)
	{
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		int cost = edge[i].first;
		if (find(a) != find(b))
		{
			merge(a, b);
			ans += cost;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1185