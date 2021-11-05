#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> capacity, flow, adj;
const int INF = 1000000000;
int N, M, K, C, T;
int network()
{

	int ret = 0;
	while (true)
	{
		vector<int> parent(N + M + 3, -1);
		queue<int> q;
		parent[0] = 0;
		q.push(0);
		while (!q.empty() && parent[N + M + 2] == -1)
		{
			int here = q.front();
			q.pop();
			for (int i = 0; i < adj[here].size(); i++)
			{
				int there = adj[here][i];
				if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
				{
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if (parent[N + M + 2] == -1) break;
		for (int p = N + M + 2; p != 0; p = parent[p])
		{
			flow[parent[p]][p]++;
			flow[p][parent[p]]--;
		}
		ret++;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	capacity.resize(N + M + 3, vector<int>(N + M + 3, 0));  adj.resize(N + M + 3);
	flow.resize(N + M + 3, vector<int>(N + M + 3, 0));
	capacity[0][N + M + 1] = N + 1;
	adj[0].push_back(N + M + 1);
	adj[N + M + 1].push_back(0);
	for (int i = 1; i <= N; i++)
	{
		capacity[N + M + 1][i] = 1;
		adj[N + M + 1].push_back(i);
		adj[i].push_back(N + M + 1);
	}
	for (int m = N + 1; m <= N + M; m++)
	{
		capacity[m][N + M + 2] = 1;
		adj[m].push_back(N + M + 2);
		adj[N + M + 2].push_back(m);
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> C;
		for (int c = 0; c < C; c++)
		{
			cin >> T;
			capacity[i][N + T] = 1;
			adj[i].push_back(N + T);
			adj[N + T].push_back(i);
		}
	}
	int ans = network();
	capacity[0][N + M + 1] = K;
	flow[0][N + M + 1] = 0;
	for (int i = 1; i <= N; i++) capacity[N + M + 1][i] = INF;
	ans += network();
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/11378