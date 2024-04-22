#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
priority_queue<pair<ll, int>> pq;
vector<int> adj[100001];
queue<int> q;
int N, M, K, S, P, Q, F, v[100001], A, B;
ll D[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K >> S;
	cin >> P >> Q;
	memset(v, -1, sizeof(v));
	for (int i = 1; i <= N; i++) D[i] = 100000000000007;
	for (int i = 0; i < K; i++)
	{
		cin >> F;
		q.push(F);
		v[F] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		if (v[here] == S) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			if (v[there] >= 0) continue;
			v[there] = v[here] + 1;
			q.push(there);
		}
	}
	pq.push({ 0, 1 });
	D[1] = 0;
	while (!pq.empty())
	{
		int here = pq.top().second;
		ll cost = -pq.top().first;
		pq.pop();
		if (D[here] < cost) continue;
		if (here == N)
		{
			if (v[N] < 0) D[N] -= P;
			else D[N] -= Q;
			cout << D[N] << '\n';
			break;
		}
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			ll nxtCost = cost;
			if (v[there] == 0) continue;
			if (v[there] < 0) nxtCost += P;
			else nxtCost += Q;
			if (D[there] > nxtCost)
			{
				D[there] = nxtCost;
				pq.push({ -nxtCost, there });
			}
		}
	}
}

// https://www.acmicpc.net/problem/11952