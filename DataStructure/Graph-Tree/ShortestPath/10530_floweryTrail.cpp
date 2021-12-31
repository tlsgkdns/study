#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1000000001;
vector<vector<pair<pair<int, int>, bool>>> adj;
int T, P, p1, p2, l, minDist, ans = 0;
vector<bool> v;
vector<int> dist;
int getDist()
{
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, 0 });
	dist[0] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int next = adj[cur][i].first.first;
			int nextCost = cost + adj[cur][i].first.second;
			if (dist[next] <= nextCost) continue;
			dist[next] = nextCost;
			pq.push({ -nextCost, next });
		}
	}
	return dist[T - 1];
}
bool dfs(int here, int cost)
{
	if (dist[here] < cost || cost > minDist) return false;
	if (here == T - 1 && cost == minDist) return true;
	bool ret = false;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first.first;
		int nCost = adj[here][i].first.second + cost;
		if (v[there] || nCost > minDist) continue;
		if (adj[here][i].second)
		{
			ret = true;
			continue;
		}
		v[there] = true;
		if (dfs(there, nCost))
		{
			ret = true;
			if (!adj[here][i].second)
			{
				adj[here][i].second = true;
				ans += adj[here][i].first.second;
			}
		}
		v[there] = false;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T >> P; adj.resize(T + 1);
	v.resize(T + 1); dist.resize(T + 1, INF);
	for (int i = 0; i < P; i++)
	{
		cin >> p1 >> p2 >> l;
		adj[p1].push_back(make_pair(make_pair(p2, l), false));
		adj[p2].push_back(make_pair(make_pair(p1, l), false));
	}
	minDist = getDist();
	dfs(0, 0);
	ans *= 2;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10530