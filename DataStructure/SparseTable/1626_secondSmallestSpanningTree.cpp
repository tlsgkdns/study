#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>

using namespace std;
using pii = pair<int, int>;
const int MAX = 50001;
const int INF = 1000000007;
unordered_map<int, int> adj[MAX];
vector<pair<int, pii>> edges;
int V, E, depth[MAX], A, B, C, dp[MAX][22], P[MAX], ans[MAX], cnt = 0, S = 0, p = INF;
pii L[MAX][22];
bool sel[MAX];
void dfs(int here, int parent)
{
	for (const pair<int, int> p : adj[here])
		if (p.first != parent)
		{
			depth[p.first] = depth[here] + 1;
			dp[p.first][0] = here;
			L[p.first][0] = pii(p.second, -1);
			dfs(p.first, here);
		}
}
int find(int u)
{
	if (P[u] == u) return u;
	return P[u] = find(P[u]);
}
void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u > v) swap(u, v);
	P[v] = u;
}

int solve(pair<int, pii>& ee)
{
	int a = ee.second.first;
	int b = ee.second.second;
	int w = ee.first;
	int ret = -1;
	if (depth[a] < depth[b]) swap(a, b);
	int diff = depth[a] - depth[b];
	int cnt = 0;
	while (diff)
	{
		if (diff % 2 == 1)
		{
			if (L[a][cnt].first != w)
				ret = max(ret, L[a][cnt].first);
			else if (L[a][cnt].second != -1)
				ret = max(ret, L[a][cnt].second);
			a = dp[a][cnt];
			depth[a];
		}
		diff /= 2;
		++cnt;
	}
	if (a != b) {
		for (int i = 20; i >= 0; i--) {
			if (dp[a][i] != dp[b][i]) {
				if (L[a][i].first != w)
					ret = max(ret, L[a][i].first);
				else if (L[a][i].second != -1)
					ret = max(ret, L[a][i].second);
				if (L[b][i].first != w)
					ret = max(ret, L[b][i].first);
				else if (L[b][i].second != -1)
					ret = max(ret, L[b][i].second);
				a = dp[a][i];
				b = dp[b][i];
			}
		}
		if (L[a][0].first != w)
			ret = max(ret, L[a][0].first);
		else if (L[a][0].second != -1)
			ret = max(ret, L[a][0].second);
		if (L[b][0].first != w)
			ret = max(ret, L[b][0].first);
		else if (L[b][0].second != -1)
			ret = max(ret, L[b][0].second);

		a = dp[a][0];
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> V >> E;
	for (int i = 0; i <= V; i++) P[i] = i;
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		edges.push_back({ C, {A, B} });
	}
	std::sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (find(a) != find(b))
		{
			merge(a, b);
			adj[a][b] = cost;
			adj[b][a] = cost;
			S += cost;
			++cnt;
			sel[i] = true;
		}
	}
	depth[0] = depth[1] = -1;
	dfs(1, 0);
	if (cnt != V - 1)
	{
		cout << -1 << '\n';
	}
	else
	{
		for (int j = 0; j <= 20; j++) {
			for (int i = 1; i <= V; i++) {
				if (dp[i][j] >= 0 && dp[dp[i][j]][j] >= 0) {
					pii b = L[i][j]; pii a = L[dp[i][j]][j];
					vector<int> tmp = { b.first, b.second, a.first, a.second };
					int f = -1, s = -1;
					for (int n : tmp) f = max(f, n);
					for (int n : tmp)
						if (n != f)
							s = max(s, n);
					L[i][j + 1] = { f, s };
					dp[i][j + 1] = dp[dp[i][j]][j];
				}
			}
		}
		for (int i = 0; i < edges.size(); i++)
		{
			if (sel[i]) continue;
			int t = solve(edges[i]);
			if (t == -1 || edges[i].first == t) continue;
			p = min(p, edges[i].first - t);
		}
		if (p == INF) cout << -1 << '\n';
		else cout << S + p << '\n';
	}
}


// https://www.acmicpc.net/problem/1626