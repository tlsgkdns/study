#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
const ll INF = 100000000000;
const int MAX = 100001;
int N, M, A, B;
ll ans = 0;
vector<pair<int, int>> adj[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A].push_back({ B, i });
		adj[B].push_back({ A, i });
	}
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, 1 });
	vector<ll> dist(N + 1, INF);
	dist[1] = 0;
	while (!pq.empty())
	{
		ll t = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < t) continue;
		if (here == N)
		{
			ans = t;
			break;
		}
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int period = t % M;
			ll nextTime = t + 1 + (ll)((period > adj[here][i].second) ? M - period + adj[here][i].second : adj[here][i].second - period);
			if (dist[there] <= nextTime) continue;
			dist[there] = nextTime;
			pq.push({ -nextTime, there });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/24042