#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 1e15;
const int MAX = 100001;
vector<pii> adj[MAX];
int N, M, A, B, P, Q, R;
ll C;
bool dijkstra(ll lm)
{
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, A });
	vector<ll> dist(N + 1, INF);
	dist[A] = 0;
	while (!pq.empty())
	{
		ll cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (here == B) return true;
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			ll nxtCost = (ll)adj[here][i].second + cost;
			if (nxtCost > C || dist[there] <= nxtCost || adj[here][i].second > lm) continue;
			dist[there] = nxtCost;
			pq.push({ -nxtCost, there });
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> A >> B >> C;
	for (int i = 0; i < M; i++)
	{
		cin >> P >> Q >> R;
		adj[P].push_back({ Q, R });
		adj[Q].push_back({ P, R });
	}
	ll l = 0, r = C + 1;
	while (l + 1 < r)
	{
		ll m = (l + r) / 2;
		if (dijkstra(m)) r = m;
		else l = m;
	}
	if (!dijkstra(r)) r = -1;
	cout << r << '\n';
}

// https://www.acmicpc.net/problem/20183