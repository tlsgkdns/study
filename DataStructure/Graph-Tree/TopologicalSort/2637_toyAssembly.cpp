#include <iostream>
#include <queue>

using namespace std;
const int MAX = 101;
vector<pair<int, int>> adj[MAX];
int N, M, indegree[MAX], X, Y, K, part[MAX][MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y >> K;
		indegree[X]++;
		adj[Y].push_back({ X, K });
	}
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
		{
			q.push(i);
			part[i][i] = 1;
		}
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			for (int n = 1; n <= N; n++)
				part[there][n] += part[here][n] * adj[here][i].second;
			indegree[there]--;
			if (indegree[there] == 0) q.push(there);
		}
	}
	for (int n = 1; n <= N; n++)
		if (part[N][n] > 0)
			cout << n << " " << part[N][n] << '\n';
}

// https://www.acmicpc.net/problem/2637