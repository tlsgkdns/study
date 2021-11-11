#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dist, parent;
stack<int> ans;
int N, M, a, b, c, src, dst;
const int INF = 1000000001;

void dijkstra()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, src });
	dist[src] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int next = adj[cur][i].first;
			int newCost = adj[cur][i].second + cost;
			if (newCost < dist[next])
			{
				dist[next] = newCost;
				parent[next] = cur;
				pq.push({ -dist[next], next });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> M;
	adj.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}
	dist.resize(N + 1, INF);
	parent.resize(N + 1, -1);
	cin >> src >> dst;
	dijkstra();
	int node = dst;
	while (node != src)
	{
		ans.push(node);
		node = parent[node];
	}
	ans.push(src);
	cout << dist[dst] << '\n';
	cout << ans.size() << '\n';
	while (!ans.empty())
	{
		cout << ans.top() << " ";
		ans.pop();
	}
	cout << '\n';
}

// https://www.acmicpc.net/problem/11779