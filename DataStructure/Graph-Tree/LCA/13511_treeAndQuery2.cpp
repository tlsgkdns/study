#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>;

using namespace std;
using ll = long long;

vector<vector<pair<int, int>>> adj;
vector<vector<int>> dp;
vector<bool> v;
vector<ll> depth, dist, ans;
int N, M, mL, U, V, K, w, q;
const int MX = 100001;

void dfs(int here, ll weight)
{
	dist[here] = weight;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		int cost = adj[here][i].second;
		if (v[there]) continue;
		v[there] = true;
		dfs(there, weight + cost);
	}
}
void setGraph(int here, int parent)
{

	depth[here] = depth[parent] + 1;
	dp[here][0] = parent;
	for (int i = 1; i <= mL; i++)
		dp[here][i] = dp[dp[here][i - 1]][i - 1];
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		if (there == parent) continue;
		setGraph(there, here);
	}
}

int getLCA(int a, int b)
{
	if (depth[a] != depth[b])
	{
		if (depth[a] > depth[b]) swap(a, b);
		for (int i = mL; i >= 0; i--)
			if (depth[a] <= depth[dp[b][i]])
				b = dp[b][i];
	}
	int ret = a;
	if (a != b)
	{
		for (int i = mL; i >= 0; i--)
		{
			if (dp[a][i] != dp[b][i])
			{
				a = dp[a][i];
				b = dp[b][i];
			}
			ret = dp[a][i];
		}
	}
	return ret;
}

int getkthNode(ll lcaDepth, int a, int b, int k)
{
	int ret, d = 0;
	if (depth[a] - lcaDepth >= k)
	{
		ret = a;
	}
	else
	{
		ret = b;
		k = depth[a] + depth[b] - 2 * lcaDepth - k;
	}
	for (int i = mL; i >= 0; i--)
	{
		if (d == k) break;
		if (pow(2, i) + d > k) continue;
		d += pow(2, i);
		ret = dp[ret][i];
	}
	return ret;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	adj.resize(N + 1); dp.resize(N + 1, vector<int>(20));
	dist.resize(N + 1); depth.resize(N + 1);
	v.resize(N + 1, false);
	mL = floor(log2(MX));
	for (int i = 0; i < N - 1; i++)
	{
		cin >> U >> V >> w;
		adj[U].push_back({ V, w });
		adj[V].push_back({ U, w });
	}
	setGraph(1, 0);
	v[1] = true;
	dfs(1, 0);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> q;
		if (q == 1)
		{
			cin >> U >> V;
			int lca = getLCA(U, V);
			ans.push_back(dist[U] + dist[V] - 2 * dist[lca]);
		}
		else
		{
			cin >> U >> V >> K;
			ans.push_back(getkthNode(depth[getLCA(U, V)], U, V, K - 1));
		}
	}
	for (ll a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/13511