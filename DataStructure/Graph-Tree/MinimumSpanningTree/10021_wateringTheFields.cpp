#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<pair<int, int>> farm;
vector<int> parent;
vector<pair<int, pair<int, int>>> edges;
int N, C, xi, yi;
int getCost(int x1, int y1, int x2, int y2)
{
	return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

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
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> C;
	parent.resize(N);
	for (int i = 0; i < N; i++)
		parent[i] = i;
	for (int i = 0; i < N; i++)
	{
		cin >> xi >> yi;
		for (int j = 0; j < farm.size(); j++)
		{
			int c = getCost(xi, yi, farm[j].first, farm[j].second);
			if (c < C) continue;
			edges.push_back({ c, {i, j} });
		}
		farm.push_back({ xi, yi });
	}
	sort(edges.begin(), edges.end());
	int ans = 0, cnt = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int from = edges[i].second.first;
		int to = edges[i].second.second;
		if (find(from) == find(to)) continue;
		ans += cost;
		cnt++;
		merge(from, to);
	}
	if (cnt != N - 1) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10021