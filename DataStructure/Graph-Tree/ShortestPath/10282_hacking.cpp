#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1000000000;
int T, n, d, c, a, b, s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<pair<int, int>> ans;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int cnt = 0, far = -1;
		cin >> n >> d >> c;
		vector<vector<pair<int, int>>> adj(n + 1);
		vector<int> dist(n + 1, INF);
		priority_queue<pair<int, int>> pq;
		dist[c] = 0;
		pq.push({ 0, c });
		for (int i = 0; i < d; i++)
		{
			cin >> a >> b >> s;
			adj[b].push_back({ a, s });
		}
		while (!pq.empty())
		{
			int distance = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (dist[here] < distance) continue;
			for (int i = 0; i < adj[here].size(); i++)
			{
				int there = adj[here][i].first;
				int next = distance + adj[here][i].second;
				if (next < dist[there])
				{
					dist[there] = next;
					pq.push({ -next, there });
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] == INF) continue;
			cnt++;
			if (far < dist[i]) far = dist[i];
		}
		ans.push_back({ cnt, far });
	}
	for (pair<int, int> a : ans)
		cout << a.first << " " << a.second << '\n';
}
// https://www.acmicpc.net/problem/10282