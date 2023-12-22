#include <iostream>
#include <queue>
using namespace std;

const int INF = 1000000007;
vector<pair<int, int>> adj[5001];
int D[5001][2];
int V, E, P, A, B, C;

void dijkstra(int s, int idx)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s }); D[s][idx] = 0;
	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (D[here][idx] > cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nxtCost = adj[here][i].second + cost;
			if (D[there][idx] > nxtCost)
			{
				D[there][idx] = nxtCost;
				pq.push({ -nxtCost, there });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E >> P;
	for (int i = 1; i <= V; i++)
	{
		D[i][0] = INF;
		D[i][1] = INF;
	}
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	dijkstra(1, 0); dijkstra(P, 1);
	if (D[V][0] < D[P][0] + D[V][1]) cout << "GOOD BYE\n";
	else cout << "SAVE HIM\n";
}

// https://www.acmicpc.net/problem/18223