#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int MAX = 1001, INF = 1000000001;
int N, M, X, S, D, T, ans = 0;
vector<pii> adj1[MAX], adj2[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		cin >> S >> D >> T;
		adj1[S].push_back({ D, T });
		adj2[D].push_back({ S, T });
	}
	priority_queue<pii> pq;
	vector<int> dist1(N + 1, INF), dist2(N + 1, INF);
	pq.push({ 0, X });
	dist1[X] = 0; dist2[X] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist1[here] < cost) continue;
		for (int i = 0; i < adj1[here].size(); i++)
		{
			int there = adj1[here][i].first;
			int nxt = adj1[here][i].second + cost;
			if (dist1[there] <= nxt) continue;
			dist1[there] = nxt;
			pq.push({ nxt, there });
		}
	}
	pq.push({ 0, X });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist2[here] < cost) continue;
		for (int i = 0; i < adj2[here].size(); i++)
		{
			int there = adj2[here][i].first;
			int nxt = adj2[here][i].second + cost;
			if (dist2[there] <= nxt) continue;
			dist2[there] = nxt;
			pq.push({ nxt, there });
		}
	}
	for (int i = 1; i <= N; i++)
		ans = max(ans, dist1[i] + dist2[i]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1238