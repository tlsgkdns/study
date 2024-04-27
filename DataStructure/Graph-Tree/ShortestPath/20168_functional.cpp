#include <iostream>
#include <queue>
using namespace std;

vector<pair<int, int>> adj[11];
int N, M, C, A, B, ans = -1, a, b, c, D[11];

bool solve(int lim)
{
	for (int i = 1; i <= N; i++) D[i] = 1000000007;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, A });
	D[A] = 0;
	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (here == B)
		{
			return cost <= C;
		}
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nxtCost = adj[here][i].second;
			if (nxtCost > lim) continue;
			if (D[there] > nxtCost + cost)
			{
				D[there] = nxtCost + cost;
				pq.push({ -(nxtCost + cost), there });
			}
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> A >> B >> C;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	for (int c = 0; c <= 1000; c++)
		if (solve(c))
		{
			ans = c;
			break;
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/20168