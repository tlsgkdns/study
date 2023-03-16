#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int, pair<double, double>>> adj[1001];
int N, M, A, B, C, F, ans = 0;
double dist[1001];
struct cmp
{
	bool operator()(pair<int, pair<double, double>> p1, pair<int, pair<double, double>> p2)
	{
		return (p1.second.first / p1.second.second) < (p2.second.first / p2.second.second);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C >> F;
		adj[A].push_back({ B, {F, C} });
		adj[B].push_back({ A, {F, C} });
	}
	priority_queue<pair<int, pair<double, double>>, vector<pair<int, pair<double, double>>>, cmp> pq;
	pq.push({ 1, {1001, 0} }); dist[1] = 1000000000;
	while (!pq.empty())
	{
		int here = pq.top().first;
		double flow = pq.top().second.first;
		double cost = pq.top().second.second;
		pq.pop();
		double ratio = (cost > 0) ? (flow / cost) : 0;
		if (here == N)
		{
			ans = ratio * 1000000;
			break;
		}
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			double nxtFlow = min(flow, adj[here][i].second.first);
			double nxtCost = cost + adj[here][i].second.second;
			if ((nxtFlow / nxtCost) <= dist[there]) continue;
			dist[there] = nxtFlow / nxtCost;
			pq.push({ there, {nxtFlow, nxtCost} });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/18262