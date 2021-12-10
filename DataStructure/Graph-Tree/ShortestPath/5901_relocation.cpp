#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> dists;
vector<int> markets;
vector<bool> v, mark;
int N, M, K, S1, S2, L, ans = INF;

void dijkstra(int src)
{
	vector<int> dist(N + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, src });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] < cost) continue;
		for (int i = 0; i < adj[now].size(); i++)
		{
			int next = adj[now][i].first;
			int nextCost = cost + adj[now][i].second;
			if (nextCost < dist[next])
			{
				dist[next] = nextCost;
				pq.push({ -nextCost, next });
			}
		}
	}
	dists[src] = dist;
}

void solve(int start, int d, int cur, int trav)
{
	if (d == K)
	{
		ans = min(ans, trav + dists[cur][start]);
		return;
	}
	for (int i = 0; i < K; i++)
	{
		if (v[i]) continue;
		v[i] = true;
		solve(start, d + 1, markets[i], dists[markets[i]][cur] + trav);
		v[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	adj.resize(N + 1);
	markets.resize(K); dists.resize(N + 1);
	v.resize(K); mark.resize(N + 1);
	for (int i = 0; i < K; i++)
	{
		cin >> markets[i];
		mark[markets[i]] = true;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> S1 >> S2 >> L;
		adj[S1].push_back({ S2, L });
		adj[S2].push_back({ S1, L });
	}
	for (int i = 0; i < K; i++) dijkstra(markets[i]);
	for (int n = 1; n <= N; n++)
	{
		if (mark[n]) continue;
		solve(n, 0, n, 0);
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/5901