#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> adj;
const int INF = 1000000000;
int C, V, c1, c2, e, ans;

void dijkstra()
{
	priority_queue<pair<int, pair<int, bool>>> pq;
	vector<vector<int>> dist(C + 1, vector<int>(2, INF));
	dist[1][0] = 0;
	pq.push({ 0, {1, true} });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second.first;
		bool even = pq.top().second.second;
		pq.pop();
		if (dist[here][even] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nextCost = cost + adj[here][i].second;
			if (dist[there][!even] <= nextCost) continue;
			dist[there][!even] = nextCost;
			pq.push({ -nextCost, {there, !even} });
		}
	}
	if (dist[C][1] == INF) ans = -1;
	else ans = dist[C][1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> C >> V;
	adj.resize(C + 1);
	for (int i = 0; i < V; i++)
	{
		cin >> c1 >> c2 >> e;
		adj[c1].push_back({ c2, e });
		adj[c2].push_back({ c1, e });
	}
	dijkstra();
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13595