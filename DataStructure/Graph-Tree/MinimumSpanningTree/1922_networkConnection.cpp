#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, A, B, C, ans = 0;
int parent[1001];
vector<pair<int, pair<int, int>>> edge;
int find(int u)
{
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
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
	while (M--)
	{
		cin >> A >> B >> C;
		edge.push_back({ C, {A, B} });
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < (int)edge.size(); i++)
	{
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (find(a) == find(b)) continue;
		ans += edge[i].first;
		merge(a, b);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1922