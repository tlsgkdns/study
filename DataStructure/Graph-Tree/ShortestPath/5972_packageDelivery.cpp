#include <iostream>
#include <queue>

using namespace std;

const int MAX = 50001, INF = 1000000000;
vector<pair<int, int>> adj[MAX];
int N, M, A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	vector<int> dist(N + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nxt = adj[here][i].second + cost;
			if (dist[there] <= nxt) continue;
			dist[there] = nxt;
			pq.push({ -nxt, there });
		}
	}
	cout << dist[N] << '\n';
}

// https://www.acmicpc.net/problem/5972