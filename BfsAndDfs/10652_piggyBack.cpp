#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adj[40001];
int B, E, P, N, M, a, b, D[40001][3], ans = 2000000001;
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	int idx = (s == N - 1) ? 2 : s;
	D[s][idx] = 0;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			if (D[there][idx] >= 0) continue;
			D[there][idx] = D[here][idx] + 1;
			q.push(there);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> B >> E >> P >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	memset(D, -1, sizeof(D));
	bfs(0); bfs(1); bfs(N - 1);
	for (int i = 0; i < N; i++)
		ans = min(ans, D[i][0] * B + D[i][1] * E + D[i][2] * P);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10652