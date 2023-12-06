#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int T, K, M, P, A, B, indegree[1001], S[1001], cnt[1001];
vector<int> adj[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> K >> M >> P;
		for (int i = 1; i <= M; i++)
		{
			adj[i].clear();
			indegree[i] = 0; S[i] = 0;
			cnt[i] = 0;
		}
		for (int i = 0; i < P; i++)
		{
			cin >> A >> B;
			adj[A].push_back(B);
			++indegree[B];
		}
		queue<int> q;
		for (int i = 1; i <= M; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
				S[i] = 1;
			}
		}
		while (!q.empty())
		{
			int here = q.front();
			q.pop();
			for (int i = 0; i < adj[here].size(); i++)
			{
				int there = adj[here][i];
				--indegree[there];
				if (S[there] < S[here])
				{
					S[there] = S[here];
					cnt[there] = 1;
				}
				else if (S[there] == S[here])
					++cnt[there];
				if (indegree[there] == 0)
				{
					if (cnt[there] > 1)
						++S[there];
					q.push(there);
				}
			}
		}
		cout << K << " " << S[M] << '\n';
	}
}

// https://www.acmicpc.net/problem/9470