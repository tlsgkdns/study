#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <limits>
using namespace std;
vector<pair<int, double>> adj[4001];
int N, K, A, B, D, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> A >> B >> D;
		adj[A].push_back({ B, D });
		adj[B].push_back({ A, D });
	}
	vector<double> dist1(N + 1, numeric_limits<double>().max());
	vector<vector<double>> dist2(N + 1, vector<double>(2, numeric_limits<double>().max()));
	dist1[1] = 0; dist2[1][1] = 0;
	priority_queue<pair<double, int>> pq1;
	priority_queue<pair<double, pair<int, bool>>> pq2;
	pq1.push({ 0, 1 }); pq2.push({ 0, {1, true} });
	while (!pq1.empty())
	{
		double cost = -pq1.top().first;
		int here = pq1.top().second;
		pq1.pop();
		if (dist1[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			double nxtCost = adj[here][i].second + cost;
			if (dist1[there] <= nxtCost) continue;
			dist1[there] = nxtCost;
			pq1.push({ -nxtCost, there });
		}
	}
	while (!pq2.empty())
	{
		double cost = -pq2.top().first;
		int here = pq2.top().second.first;
		bool run = pq2.top().second.second;
		pq2.pop();
		if (dist2[here][run] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			double nxtCost = (run) ? ((adj[here][i].second / 2)) + cost : (adj[here][i].second * 2) + cost;
			if (dist2[there][!run] <= nxtCost) continue;
			dist2[there][!run] = nxtCost;
			pq2.push({ -nxtCost, {there, !run} });
		}
	}
	for (int n = 1; n <= N; n++)
		ans += (dist1[n] < min(dist2[n][0], dist2[n][1]));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16118