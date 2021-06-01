#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, a, b;
vector<vector<int>> adj;
priority_queue<int, vector<int>, greater<int>> q;
vector<int> entry, ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	adj.resize(N + 1); entry.resize(N + 1, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		entry[b]++;
	}
	for (int i = 1; i <= N; i++)
		if (entry[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int f = q.top();
		q.pop();
		ans.push_back(f);
		for (int nxt : adj[f])
		{
			entry[nxt]--;
			if (entry[nxt] == 0) q.push(nxt);
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/1766