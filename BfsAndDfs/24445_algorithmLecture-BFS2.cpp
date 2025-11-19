#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> adj[100001];
int u, v, N, M, R, ans[100001], cnt = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		adj[u].push_back(-v);
		adj[v].push_back(-u);
	}
	for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());
	queue<int> q;
	q.push(R);
	ans[R] = cnt++;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int& nxt : adj[now])
			if (ans[-nxt] == 0)
			{
				ans[-nxt] = cnt++;
				q.push(-nxt);
			}
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/24445