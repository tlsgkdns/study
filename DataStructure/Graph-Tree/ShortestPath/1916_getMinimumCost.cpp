#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 10000000001;
priority_queue<pair<ll, int>> pq;
ll adj[1001][1001];
int N, M, A, B, C, S, D;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	vector<ll> dist(N + 1, INF);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			adj[i][j] = INF;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A][B] = min(adj[A][B], (ll)C);
	}
	cin >> S >> D;
	pq.push({ 0, S });
	dist[S] = 0;

	while (!pq.empty())
	{
		int here = pq.top().second;
		ll cost = pq.top().first;
		pq.pop();
		for (int there = 1; there <= N; there++)
		{
			if (dist[there] <= cost + adj[here][there]) continue;
			dist[there] = cost + adj[here][there];
			pq.push({ dist[there], there });
		}
	}
	cout << dist[D] << '\n';
}

// https://www.acmicpc.net/problem/1916