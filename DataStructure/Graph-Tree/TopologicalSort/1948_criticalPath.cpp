#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10001;
vector<pair<int, int>> adj[MAX], adj2[MAX];
vector<int> P[MAX];
int N, M, S, D, T[MAX], a, b, c, indegree[MAX], cnt = 0;
bool v[MAX];
vector<int> R;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj2[b].push_back({ a, c });
		++indegree[b];
	}
	cin >> S >> D;
	queue<int> q;
	q.push(S);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			T[there] = max(T[there], adj[here][i].second + T[here]);
			--indegree[there];
			if (indegree[there] == 0) q.push(there);
		}
	}
	q.push(D);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj2[here].size(); i++)
		{
			int there = adj2[here][i].first;
			int cost = adj2[here][i].second;
			if (T[there] == T[here] - cost)
			{
				if (!v[there])
				{
					v[there] = true;
					q.push(there);
				}
				++cnt;
			}
		}
	}
	cout << T[D] << '\n' << cnt << '\n';
}

// https://www.acmicpc.net/problem/1948