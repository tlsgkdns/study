#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using piii = pair<int, pair<int, int>>;
int parent[100001], N, M, A, B, C, U, V;
vector<piii> edges;

int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
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
	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		edges.push_back({ C, {A, B} });
	}
	int ans = 0, m = 0;
	sort(edges.begin(), edges.end());
	for (int i = 0; i < M; i++)
	{
		U = edges[i].second.first;
		V = edges[i].second.second;
		if (find(U) == find(V)) continue;
		merge(U, V);
		ans += edges[i].first;
		m = max(m, edges[i].first);
	}
	ans -= m;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1647