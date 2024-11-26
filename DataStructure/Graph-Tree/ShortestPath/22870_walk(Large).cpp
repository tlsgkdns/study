#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int MAX = 200001;
vector<pair<int, ll>> adj[MAX];
int N, M, S, E, A, B, C;
ll dist[MAX], ans = 0;
bool v[MAX];
ll dijkstra(int s, int e)
{
	priority_queue<pair<ll, int>> pq;
	ll ret = 0;
	pq.push({ 0, s });
	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[s] = 0;
	while (!pq.empty())
	{
		int here = pq.top().second;
		ll cost = -pq.top().first;
		pq.pop();
		if (here == e && ret == 0)
		{
			ret = cost;
		}
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			ll nxtCost = adj[here][i].second + cost;
			if (v[there]) continue;
			if (dist[there] > nxtCost)
			{
				dist[there] = nxtCost;
				pq.push({ -nxtCost, there });
			}
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());
	cin >> S >> E;
	ans += dijkstra(E, S);
	vector<int> route;
	int now = S;
	ll cost = 0;
	while (now != E)
	{
		for (int i = 0; i < adj[now].size(); i++)
		{
			int nxt = adj[now][i].first;
			ll nxtCost = cost + adj[now][i].second;
			if (nxtCost + dist[nxt] == dist[S])
			{
				cost = nxtCost;
				v[nxt] = true;
				now = nxt;
				break;
			}
		}
	}
	v[E] = false;
	ans += dijkstra(S, E);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/22870