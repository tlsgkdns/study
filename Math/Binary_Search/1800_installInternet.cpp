#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000002;
vector<vector<pair<int, int>>> adj;
int N, P, K;

bool dijkstra(int lm)
{
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(0, 1)));
	vector<vector<int>> dist(N + 1, vector<int>(K + 1, INF));
	dist[1][0] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int pass = pq.top().second.first;
		int here = pq.top().second.second;
		pq.pop();
		if (here == N) return true;
		if (dist[here][pass] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nCost = max(adj[here][i].second, cost);
			int nPass = pass;
			if (nCost >= lm)
			{
				nPass++;
				nCost = cost;
			}
			if (nPass > K || dist[there][nPass] <= nCost) continue;
			dist[there][nPass] = nCost;
			pq.push(make_pair(-nCost, make_pair(nPass, there)));
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P >> K;
	adj.resize(N + 1);
	int u, v, c, l = 0, r = INF;
	for (int i = 0; i < P; i++)
	{
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (dijkstra(m)) r = m;
		else l = m;
	}
	if (l >= INF - 1) l = -1;
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/1800