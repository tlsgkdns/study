#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000

using namespace std;
using P = pair<int, int>;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int ptoi(P p, int n)
{
	return p.first * n + p.second;
}
P itop(int i, int n)
{
	return make_pair(i / n, i % n);
}
int getMin(vector<vector<int>>& cave)
{
	int n = cave.size();
	vector<int> dist(n * n + 1, INF);
	vector<bool> visited(n * n + 1, false);
	priority_queue<pair<int, int>> pq;
	pq.push({ cave[0][0], 0 });
	dist[0] = cave[0][0];
	visited[0] = true;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second; P pos = itop(here, n);
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = pos.first + dy[i];
			int nx = pos.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			P np = make_pair(ny, nx); int ni = ptoi(np, n);
			if (visited[ni]) continue;
			visited[ni] = true;
			if (dist[here] + cave[ny][nx] < dist[ni])
			{
				dist[ni] = dist[here] + cave[ny][nx];
				pq.push(make_pair(-dist[ni], ni));
			}
		}
	}
	return dist[n * n - 1];
}
int main()
{
	vector<int> ans;
	int n;
	while (true)
	{
		cin >> n;
		if (n == 0) break;
		vector<vector<int>> c(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> c[i][j];
		int a = getMin(c);
		ans.push_back(a);
	}
	for (int i = 1; i <= ans.size(); i++)
		cout << "Problem " << i << ": " << ans[i - 1] << '\n';
}

// https://www.acmicpc.net/problem/4485

/*
two dimension map dijkstra problem
little harder than normal dijkstra problem.
*/