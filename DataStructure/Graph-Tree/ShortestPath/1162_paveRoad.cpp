#include <queue>
#include <iostream>
using namespace std;
using ll = long long;
const ll INF = 10000000000000000;
vector<pair<int, int>> adj[10001];
int N, M, K, A, B, C;
ll dist[10001][21], ans = INF;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= K; j++)
			dist[i][j] = INF;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	priority_queue<pair<ll, pair<int, int>>> pq;
	pq.push({ 0, {1, 0} }); dist[1][0] = 0;
	while (!pq.empty())
	{
		ll cost = -pq.top().first;
		int here = pq.top().second.first;
		int pave = pq.top().second.second;
		pq.pop();
		if (cost > dist[here][pave]) continue;
		if (here == N)
		{
			ans = cost;
			break;
		}
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			if (pave < K && dist[there][pave + 1] > cost)
			{
				dist[there][pave + 1] = cost;
				pq.push({ -cost, {there, pave + 1} });
			}
			ll nxtCost = adj[here][i].second + cost;
			if (dist[there][pave] > nxtCost)
			{
				dist[there][pave] = nxtCost;
				pq.push({ -nxtCost, {there, pave} });
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1162