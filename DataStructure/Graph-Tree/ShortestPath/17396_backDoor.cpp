#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
const ll INF = 1000000000000007;
vector<pair<int, int>> adj[100001];
int N, M, A[100001], a, b, t;
ll D[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		D[i] = INF;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> t;
		if (a > b) swap(a, b);
		if (A[a] && A[b]) continue;
		if (b != N - 1 && (A[a] || A[b])) continue;
		adj[a].push_back({ b, t });
		adj[b].push_back({ a, t });
	}
	priority_queue<pair<ll, int>> pq;
	D[0] = 0;
	pq.push({ 0, 0 });
	while (!pq.empty())
	{
		ll cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (D[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			ll nxtCost = adj[here][i].second + cost;
			if (D[there] <= nxtCost) continue;
			D[there] = nxtCost;
			pq.push({ -nxtCost, there });
		}
	}
	if (D[N - 1] == INF) D[N - 1] = -1;
	cout << D[N - 1] << '\n';
}

// https://www.acmicpc.net/problem/17396