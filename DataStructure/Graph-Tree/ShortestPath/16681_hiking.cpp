#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;
const int MAX = 100001;
const ll INF = 1e18;
vector<pair<int, int>> adj[MAX];
int N, M, D, E, a, b, n;
ll ans = -INF;
ll dist[MAX][2], H[MAX];
void dijkstra(int idx, int s)
{
	for (int i = 1; i <= N; i++) dist[i][idx] = INF;
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, s });
	dist[s][idx] = 0;
	while (!pq.empty())
	{
		int here = pq.top().second;
		ll cost = -pq.top().first;
		pq.pop();
		if (dist[here][idx] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			ll nxtCost = adj[here][i].second + cost;
			if (nxtCost < dist[there][idx])
			{
				dist[there][idx] = nxtCost;
				pq.push({ -nxtCost, there });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> D >> E;
	for (int i = 1; i <= N; i++)
		cin >> H[i];
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> n;
		if (H[a] == H[b]) continue;
		if (H[a] > H[b]) swap(a, b);
		adj[a].push_back({ b, n });
	}
	dijkstra(0, 1); dijkstra(1, N);
	for (int i = 2; i < N; i++)
		if (dist[i][0] < INF && dist[i][1] < INF)
			ans = max(ans, (H[i] * E) - ((dist[i][0] + dist[i][1]) * D));
	if (ans == -INF) cout << "Impossible\n";
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16681