#include <iostream>
#include <queue>
using namespace std;

const int MAX = 501;
vector<int> adj[MAX];
int N, A, indegree[MAX], T[MAX], ans[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i];
		while (true)
		{
			cin >> A;
			if (A < 0) break;
			adj[A].push_back(i);
			indegree[i]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
		{
			q.push(i);
			ans[i] = T[i];
		}
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < (int)adj[here].size(); i++)
		{
			int there = adj[here][i];
			indegree[there]--;
			ans[there] = max(ans[here] + T[there], ans[there]);
			if (!indegree[there]) q.push(there);
		}
	}
	for (int n = 1; n <= N; n++) cout << ans[n] << '\n';
}

// https://www.acmicpc.net/problem/1516