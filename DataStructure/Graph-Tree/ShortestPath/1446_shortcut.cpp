#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;
const int MAX = 10001, INF = 1000000000;
int dist[MAX];
vector<pii> adj[MAX];
int nxt[MAX], N, D, src, dst, l, idx;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> D;
	for (int i = 0; i < MAX; i++) dist[i] = INF;
	for (int i = 0; i <= D; i++) nxt[i] = D;
	for (int i = 0; i < N; i++)
	{
		cin >> src >> dst >> l;
		if (src > D) continue;
		adj[src].push_back({ dst, l });
		idx = src - 1;
		while (idx >= 0 && adj[idx].empty())
		{
			nxt[idx] = src;
			idx--;
		}
		if (idx >= 0)
			nxt[idx] = src;
	}
	priority_queue<pii> pq;
	pq.push({ 0, 0 });
	dist[0] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (here > D) continue;
		if (here == D) break;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nCost = adj[here][i].second + cost;
			if (dist[there] <= nCost) continue;
			dist[there] = nCost;
			pq.push({ -nCost, there });
		}
		if (dist[nxt[here]] <= nxt[here] - here + cost) continue;
		dist[nxt[here]] = nxt[here] - here + cost;
		pq.push({ -dist[nxt[here]], nxt[here] });
	}
	cout << dist[D] << '\n';
}

// https://www.acmicpc.net/problem/1446