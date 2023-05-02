#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 1000000007;
const int MAX = 501;
int dist[MAX], adj[MAX][MAX], N, M, S, D, U, V, P, ans = -1;
bool v[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		ans = -1;
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		vector<int> parent[MAX];
		cin >> S >> D;
		for (int i = 0; i < N; i++)
		{
			dist[i] = INF;
			for (int j = 0; j < N; j++)
				adj[i][j] = INF;
		}
		for (int i = 0; i < M; i++)
		{
			cin >> U >> V >> P;
			adj[U][V] = P;
		}
		priority_queue<pair<int, int>> pq;
		pq.push({ 0, S });
		dist[S] = 0;
		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (dist[here] < cost) continue;
			for (int there = 0; there < N; there++)
			{
				if (adj[here][there] >= INF) continue;
				int nxtCost = cost + adj[here][there];
				if (dist[there] < nxtCost) continue;
				else if (dist[there] == nxtCost)
					parent[there].push_back(here);
				else
				{
					parent[there].clear();
					parent[there].push_back(here);
					dist[there] = nxtCost;
					pq.push({ -nxtCost, there });
				}
			}
		}
		queue<int> q; q.push(D);
		memset(v, false, sizeof(v));
		v[D] = true;
		while (!q.empty())
		{
			int here = q.front();
			q.pop();
			for (int i = 0; i < parent[here].size(); i++)
			{
				int there = parent[here][i];
				adj[there][here] = INF;
				if (v[there]) continue;
				v[there] = true;
				q.push(there);
			}
		}
		for (int i = 0; i < N; i++) dist[i] = INF;
		pq.push({ 0, S });
		dist[S] = 0;
		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (dist[here] < cost) continue;
			for (int there = 0; there < N; there++)
			{
				if (adj[here][there] >= INF) continue;
				int nxtCost = cost + adj[here][there];
				if (dist[there] <= nxtCost) continue;
				dist[there] = nxtCost;
				pq.push({ -nxtCost, there });
			}
		}
		ans = dist[D];
		if (ans >= INF) ans = -1;
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/5719