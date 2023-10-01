#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100001;
vector<pair<int, pair<int, int>>> adj[MAX];
int V, E, X, Y, T, K, D[MAX][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;
	for (int i = 1; i <= V; i++) D[i][0] = D[i][1] = 2000000001;
	for (int i = 0; i < E; i++)
	{
		cin >> X >> Y >> T >> K;
		adj[X].push_back({ Y, {T, K} });
		adj[Y].push_back({ X, {T, K} });
	}
	priority_queue<pair<pair<int, bool>, int>> pq;
	pq.push({ {0, false}, 1 });
	while (!pq.empty())
	{
		int here = pq.top().second;
		bool d = pq.top().first.second;
		int cost = -pq.top().first.first;
		pq.pop();
		if (D[here][d] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int t = adj[here][i].second.second;
			int nxtCost = adj[here][i].second.first + cost;
			if (!d && D[there][true] > nxtCost - t)
			{
				D[there][true] = nxtCost - t;
				pq.push({ {-D[there][true], true}, there });
			}
			if (D[there][d] > nxtCost)
			{
				D[there][d] = nxtCost;
				pq.push({ {-nxtCost, d}, there });
			}
		}
	}
	for (int i = 2; i <= V; i++) cout << D[i][1] << '\n';
}

// https://www.acmicpc.net/problem/19701