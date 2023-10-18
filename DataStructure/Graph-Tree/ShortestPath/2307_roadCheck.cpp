#include <iostream>
#include <queue>
using namespace std;

const int INF = 1000000007;
vector<pair<int, pair<int, int>>> adj[1001];
int N, M, D[1002][5002], A, B, T;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			D[i][j] = INF;
	for (int i = 1; i <= M; i++)
	{
		cin >> A >> B >> T;
		adj[A].push_back({ i, {B, T} });
		adj[B].push_back({ i, {A, T} });
	}
	for (int b = 0; b <= M; b++)
	{
		priority_queue<pair<int, int>> pq;
		D[1][b] = 0;
		pq.push({ 0, 1 });
		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (D[here][b] < cost) continue;
			if (here == N) break;
			for (int i = 0; i < adj[here].size(); i++)
			{
				if (adj[here][i].first == b) continue;
				int there = adj[here][i].second.first;
				int nxtCost = adj[here][i].second.second + cost;
				if (D[there][b] <= nxtCost) continue;
				D[there][b] = nxtCost;
				pq.push({ -nxtCost, there });
			}
		}
	}
	int d1 = D[N][0], d2 = 0;
	for (int i = 1; i <= M; i++) d2 = max(d2, D[N][i]);
	if (d2 >= INF) cout << -1 << '\n';
	else cout << d2 - d1 << '\n';
}

// https://www.acmicpc.net/problem/2307