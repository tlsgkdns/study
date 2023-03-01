#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int N, M, X, Y, W;
const ll MOD = 1e9;
vector<pair<int, pair<int, int>>> L;
ll ans = 0, S = 0;
int parent[100001], sz[100001];
int find(int u)
{
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
	if (u > v) swap(u, v);
	u = find(u); v = find(v);
	parent[u] = v;
	sz[v] += sz[u];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y >> W;
		S += W;
		L.push_back({ -W, {X, Y} });
	}
	sort(L.begin(), L.end());
	for (int i = 0; i < M; i++)
	{
		int u = L[i].second.first;
		int v = L[i].second.second;
		if (find(u) != find(v))
		{
			ans += S * sz[find(u)] * sz[find(v)];
			ans %= MOD;
			merge(u, v);
		}
		S += L[i].first;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2463