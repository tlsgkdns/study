#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 1e9 + 7;
vector<pair<int, int>> adj[100001];
int N, M, S[3], D, E, L, ans = 1, dist[100001][3], f = 0;

void dijkstra(int idx)
{
	for (int i = 1; i <= N; i++) dist[i][idx] = INF;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, S[idx] });
	dist[S[idx]][idx] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here][idx] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int nxtCost = cost + adj[here][i].second;
			int there = adj[here][i].first;
			if (dist[there][idx] > nxtCost)
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
	cin >> N;
	for (int i = 0; i < 3; i++) cin >> S[i];
	cin >> M;
	while (M--)
	{
		cin >> D >> E >> L;
		adj[D].push_back({ E, L });
		adj[E].push_back({ D, L });
	}
	for (int i = 0; i < 3; i++) dijkstra(i);
	for (int i = 1; i <= N; i++)
	{
		int d = min(dist[i][0], min(dist[i][1], dist[i][2]));
		if (f < d)
		{
			f = d;
			ans = i;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/22865