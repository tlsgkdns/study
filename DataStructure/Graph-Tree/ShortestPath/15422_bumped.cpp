#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const ll INF = 1000000000000007;
int N, M, F, S, T, I, J, C, U, V;
ll D[50001][2];
vector<pair<int, ll>> adj[50001];
vector<int> flight[50001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> F >> S >> T;
	for (int i = 0; i < N; i++) D[i][0] = D[i][1] = INF;
	for (int i = 0; i < M; i++)
	{
		cin >> I >> J >> C;
		adj[I].push_back({ J, C });
		adj[J].push_back({ I, C });
	}
	for (int i = 0; i < F; i++)
	{
		cin >> U >> V;
		flight[U].push_back(V);
	}
	priority_queue<pair<ll, pair<int, bool>>> pq;
	pq.push({ 0, {S, true} });
	D[S][1] = 0;
	while (!pq.empty())
	{
		ll cost = -pq.top().first;
		int here = pq.top().second.first;
		bool f = pq.top().second.second;
		pq.pop();
		if (here == T)
		{
			cout << D[here][f] << '\n';
			break;
		}
		if (f)
		{
			for (int there : flight[here])
			{
				if (D[there][0] > cost)
				{
					D[there][0] = cost;
					pq.push({ -cost, {there, false} });
				}
			}
		}
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			ll nxtCost = adj[here][i].second + cost;
			if (D[there][f] > nxtCost)
			{
				D[there][f] = nxtCost;
				pq.push({ -nxtCost, {there, f} });
			}
		}
	}
}

// https://www.acmicpc.net/problem/15422