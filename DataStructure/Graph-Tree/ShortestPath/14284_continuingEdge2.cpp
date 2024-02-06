#include <iostream>
#include <queue>
using namespace std;

vector<pair<int, int>> adj[5001];
int N, M, A, B, C, S, T, D[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) D[i] = 1000000007;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	cin >> S >> T;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, S });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (D[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nxtCost = adj[here][i].second + cost;
			if (D[there] <= nxtCost) continue;
			D[there] = nxtCost;
			pq.push({ -nxtCost, there });
		}
	}
	cout << D[T] << '\n';
}

// https://www.acmicpc.net/problem/14284