#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 50000000000, MAX = 2501;
vector<pair<int, ll>> adj[MAX];
int price[MAX];
int N, M, A, B, C;
ll ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<pair<ll, pair<int, int>>> pq;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> price[i];
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	vector<vector<ll>> dist(N + 1, vector<ll>(MAX, INF));
	pq.push({ 0, {1, price[1]} });
	dist[1][price[1]] = 0;
	while (!pq.empty())
	{
		ll cost = -pq.top().first;
		int here = pq.top().second.first;
		int oil = pq.top().second.second;
		pq.pop();
		if (here == N)
		{
			ans = cost;
			break;
		}
		ll nxt = min(oil, price[here]);
		if (dist[here][nxt] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			ll nxtCost = cost + nxt * adj[here][i].second;
			if (dist[there][nxt] <= nxtCost) continue;
			dist[there][nxt] = nxtCost;
			pq.push({ -nxtCost, {there, nxt} });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13308