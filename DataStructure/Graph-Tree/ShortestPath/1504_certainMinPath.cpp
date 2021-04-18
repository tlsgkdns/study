#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1000000000;

vector<vector<int>> connect;
int n, e, v1, v2;
vector<int> dijkstra(int start)
{
	vector<int> distance(n + 1, INF);
	distance[start] = 0;
	priority_queue<pair<int, int>> q;
	q.push({ start, 0 });
	while (!q.empty())
	{
		int here = q.top().first;
		int cost = -q.top().second;
		q.pop();
		if (distance[here] < cost) continue;
		for (int there = 1; there <= n; there++)
			if (connect[here][there] + cost < distance[there])
			{
				distance[there] = connect[here][there] + cost;
				q.push({ there, -distance[there] });
			}
	}
	return distance;
}

int main()
{
	cin >> n >> e;
	connect.resize(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		connect[a][b] = c;
		connect[b][a] = c;
	}
	cin >> v1 >> v2;
	vector<int> oneD = dijkstra(1);
	vector<int> v1D = dijkstra(v1);
	vector<int> v2D = dijkstra(v2);
	if (oneD[v1] == INF || v1D[v2] == INF || v2D[v1] == INF || v1D[n] == INF || v2D[n] == INF || oneD[v2] == INF) cout << -1 << '\n';
	else cout << min(oneD[v1] + v1D[v2] + v2D[n], oneD[v2] + v2D[v1] + v1D[n]) << '\n';
}

// https://www.acmicpc.net/problem/1504