#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
const int MAX = 10001;
const ll INF = 10000000001;
vector<pii> adj[MAX];
vector<ll> dist[2];
vector<int> shop[2];
bool mc[MAX], star[MAX];
int lm[2];
int V, E, u, v, w, M, x, S, y, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;
	dist[0].resize(V + 1, INF); dist[1].resize(V + 1, INF);
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	cin >> M >> lm[0];
	for (int i = 0; i < M; i++)
	{
		cin >> N;
		shop[0].push_back(N);
		mc[N] = true;
	}
	cin >> S >> lm[1];
	for (int i = 0; i < S; i++)
	{
		cin >> N;
		shop[1].push_back(N);
		star[N] = true;
	}
	for (int t = 0; t < 2; t++)
	{
		priority_queue<pii> pq;
		for (int i = 0; i < shop[t].size(); i++)
		{
			pq.push({ 0, shop[t][i] });
			dist[t][shop[t][i]] = 0;
		}
		while (!pq.empty())
		{
			ll cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			for (int i = 0; i < adj[here].size(); i++)
			{
				int there = adj[here][i].first;
				ll nxtCost = (ll)adj[here][i].second + cost;
				if (dist[t][there] <= nxtCost) continue;
				dist[t][there] = nxtCost;
				pq.push({ -nxtCost, there });
			}
		}
	}
	ll ans = INF + 1;
	for (int i = 1; i <= V; i++)
	{
		if (mc[i] || star[i] || dist[0][i] > lm[0] || dist[1][i] > lm[1]) continue;
		ans = min(ans, dist[0][i] + dist[1][i]);
	}
	if (ans == INF + 1) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13911