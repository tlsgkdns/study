#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> q;
vector<int> adj[200001], ans;
int N, M, K, R[200001], X, L, Y, indegree[200001];
bool v[200001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> K;
		for (int idx = 0; idx < K; idx++)
		{
			cin >> X;
			adj[X].push_back(i);
		}
		cin >> R[i];
		indegree[i] = K;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> Y;
		v[Y] = true;
		q.push(Y);
	}
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			--indegree[there];
			if (indegree[there] == 0)
			{
				if (!v[R[there]])
				{
					v[R[there]] = true;
					q.push(R[there]);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
		if (v[i]) ans.push_back(i);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/20119