#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int N, S, D, adj[1001][1001], dist[1001];
string L[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> L[i];
		dist[i] = 1e9 + 7;
	}
	cin >> S >> D;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			int s = 0;
			for (int idx = 0; idx < L[i].size(); idx++)
				s += pow(L[i][idx] - L[j][idx], 2);
			adj[i][j] = s;
			adj[j][i] = s;
		}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, S - 1 });
	dist[S - 1] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (int there = 0; there < N; there++)
		{
			if (here == there) continue;
			int c = cost + adj[here][there];
			if (dist[there] > c)
			{
				dist[there] = c;
				pq.push({ -c, there });
			}
		}
	}
	cout << dist[D - 1] << '\n';
}

// https://www.acmicpc.net/problem/14630