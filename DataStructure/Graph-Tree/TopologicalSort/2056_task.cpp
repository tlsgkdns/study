#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> q;
vector<int> adj[10001];
int N, C, A, indegree[10001], D[10001], ans = 0, T[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i];
		cin >> indegree[i];
		if (indegree[i] == 0)
		{
			D[i] = T[i];
			q.push(i);
		}
		for (int j = 0; j < indegree[i]; j++)
		{
			cin >> A;
			adj[A].push_back(i);
		}
	}
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int& there : adj[here])
		{
			indegree[there]--;
			D[there] = max(D[here] + T[there], D[there]);
			if (indegree[there] == 0)
				q.push(there);
		}
	}
	for (int i = 1; i <= N; i++) ans = max(ans, D[i]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2056