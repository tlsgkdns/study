#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> adj[50001];
int N, F, T, L, dist1[50001], dist2[50001];
bool v[50001];
void getFar(int here, int s, int& d, int& f)
{
	if (s > d)
	{
		f = here;
		d = s;
	}
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		int l = s + adj[here][i].second;
		if (v[there]) continue;
		v[there] = true;
		getFar(there, l, d, f);
	}
}
void dfs(int here, int* dist, int s)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		int cost = s + adj[here][i].second;
		if (dist[there] >= 0) continue;
		dist[there] = cost;
		dfs(there, dist, cost);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dist1, -1, sizeof(dist1)); memset(dist2, -1, sizeof(dist2));
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> F >> T >> L;
		adj[F].push_back({ T, L });
		adj[T].push_back({ F, L });
	}
	int node1 = 0, node2 = 0, d1 = 0, d2 = 0;
	getFar(1, 0, d1, node1);
	memset(v, false, sizeof(v));
	getFar(node1, 0, d2, node2);
	dist1[node1] = 0;
	dfs(node1, dist1, 0);
	dist2[node2] = 0;
	dfs(node2, dist2, 0);
	for (int i = 1; i <= N; i++)
		cout << max(dist1[i], dist2[i]) << '\n';
}

// https://www.acmicpc.net/problem/13016