#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
priority_queue<pair<ll, int>> pq;
vector<pair<int, ll>> adj[1001];
int N, M, X, Y, Z, P[1001];
ll D[1001], ans = 0;
void dijkstra(int a, int b, bool r)
{
	for (int i = 2; i <= N; i++) D[i] = 100000000000000007L;
	D[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		int here = pq.top().second;
		ll cost = -pq.top().first;
		pq.pop();
		if (D[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			if ((here == a && there == b) || (here == b && there == a)) continue;
			ll nxtCost = adj[here][i].second + cost;
			if (D[there] > nxtCost)
			{
				if (r) P[there] = here;
				D[there] = nxtCost;
				pq.push({ -nxtCost, there });
			}
		}
	}
	ans = max(ans, D[N]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y >> Z;
		adj[X].push_back({ Y, Z });
		adj[Y].push_back({ X, Z });
	}
	dijkstra(0, 0, true);
	int now = N;
	while (now > 1)
	{
		dijkstra(P[now], now, false);
		now = P[now];
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2325