#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>> pq1;
priority_queue<pair<int, pair<int, int>>> pq2;
vector<pair<int, int>> adj[1001], ans;
int N, M, A, B, C, dist1[1001], dist2[1001], prv[1001];
bool v[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		dist1[i] = 1e9 + 7;
		dist2[i] = 1e9 + 7;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	pq1.push({ 0, 1 });
	dist1[1] = 0;
	while (!pq1.empty())
	{
		int here = pq1.top().second;
		int cost = -pq1.top().first;
		pq1.pop();
		if (dist1[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nxtCost = adj[here][i].second + cost;
			if (dist1[there] > nxtCost)
			{
				dist1[there] = nxtCost;
				pq1.push({ -nxtCost, there });
			}
		}
	}
	dist2[1] = 0;
	pq2.push({ 0, {0, 1} });
	while (!pq2.empty())
	{
		int here = pq2.top().second.second;
		int cost = -pq2.top().first;
		int scost = -pq2.top().second.first;
		pq2.pop();
		if (dist1[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nxtCost = cost + 1;
			int nxtScost = scost + adj[here][i].second;
			if (dist1[there] >= nxtScost && dist2[there] > nxtCost)
			{
				prv[there] = here;
				dist2[there] = nxtCost;
				pq2.push({ -nxtCost, {-nxtScost, there} });
			}
		}
	}
	v[1] = true;
	for (int i = 2; i <= N; i++)
	{
		if (!v[i])
		{
			int now = i;
			while (!v[now])
			{
				v[now] = true;
				ans.push_back({ now, prv[now] });
				now = prv[now];
			}
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << '\n';
}

// https://www.acmicpc.net/problem/2211