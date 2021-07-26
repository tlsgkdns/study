#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max() - 1;
int T;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, vector<int>& dst, int s, int g, int h)
{
	vector<int> dist(adj.size() + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nCost = adj[here][i].second;

			if (dist[there] > cost + nCost)
			{
				dist[there] = cost + nCost;
				pq.push(make_pair(-dist[there], there));
			}
		}
	}
	vector<int> ret;
	for (int i = 0; i < dst.size(); i++)
		if (dist[dst[i]] % 2 == 1)
			ret.push_back(dst[i]);
	sort(ret.begin(), ret.end());
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<vector<int>> ans;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n, m, t, s, g, h, a, b, d;
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		vector<vector<pair<int, int>>> adj(n + 1);
		vector<int> cand(t);
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b >> d;
			if ((a == g && b == h) || (a == h && b == g)) d = 2 * d - 1;
			else d = 2 * d;
			adj[a].push_back(make_pair(b, d));
			adj[b].push_back(make_pair(a, d));
		}
		for (int k = 0; k < t; k++)
			cin >> cand[k];
		vector<int> as = dijkstra(adj, cand, s, g, h);
		ans.push_back(as);
	}
	for (int i = 0; i < ans.size(); i++)
	{
		for (int a : ans[i])
			cout << a << " ";
		cout << '\n';
	}
}
// https://www.acmicpc.net/problem/9370
/*
Learned that the result may say whether it passed specific path. By even odd number
*/