#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
vector<pair<int, int>> adj[1001];

priority_queue<pair<int, int>> pq;
priority_queue<int> D[1001];
int N, M, K;
int A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
	}
	pq.push({ 0, 1 });
	D[1].push(0);
	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nxtCost = adj[here][i].second + cost;
			if (D[there].size() < K) D[there].push(nxtCost);
			else
			{
				if (D[there].top() <= nxtCost) continue;
				D[there].pop();
				D[there].push(nxtCost);
			}
			pq.push({ -nxtCost, there });
		}
	}
	for (int i = 1; i <= N; i++)
		if (D[i].size() < K) cout << -1 << '\n';
		else cout << D[i].top() << '\n';
}

// https://www.acmicpc.net/problem/1854