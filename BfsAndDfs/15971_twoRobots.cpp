#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj[100003];
int N, S, D, A, B, C, ans = 2000000001;
int dist[100003][2];
void dfs(int here, int st, int d)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		int cost = adj[here][i].second + d;
		if (dist[there][st] >= 0) continue;
		dist[there][st] = cost;
		dfs(there, st, cost);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dist, -1, sizeof(dist));
	cin >> N >> S >> D;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	dist[S][0] = 0; dist[D][1] = 0;
	dfs(S, 0, 0); dfs(D, 1, 0);
	for (int i = 1; i <= N; i++)
		for (int idx = 0; idx < adj[i].size(); idx++)
			ans = min(ans, min(dist[i][0] + dist[i][1], min(dist[i][0] + dist[adj[i][idx].first][1], dist[adj[i][idx].first][0] + dist[i][1])));
	if (ans == 2000000001) ans = 0;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15971