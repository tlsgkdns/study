#include <iostream>
#include <queue>

using namespace std;

int N, indegree[51], cnt = 0, ans[51];
char ch;
bool adj[51][51];
priority_queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; cnt = N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			adj[j][i] = (ch - '0');
			if (adj[j][i]) indegree[i]++;
		}
	for (int i = 0; i < N; i++)
		if (indegree[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int here = q.top();
		ans[here] = cnt--;
		q.pop();
		for (int there = 0; there < N; there++)
			if (adj[here][there])
			{
				indegree[there]--;
				if (indegree[there] == 0)
					q.push(there);
			}
	}
	if (cnt != 0) cout << -1 << '\n';
	else
	{
		for (int i = 0; i < N; i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/1432