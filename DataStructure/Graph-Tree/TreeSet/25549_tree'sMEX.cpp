#include <iostream>
#include <set>
#include <queue>

using namespace std;

const int MAX = 200001;
set<int> S[MAX];
int N, P[MAX], V, indegree[MAX], parent[MAX], ans[MAX];

int find(int a)
{
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		cin >> P[i];
		if (P[i] < 0) continue;
		indegree[P[i]]++;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> V;
		S[i].insert(V);
	}
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int now = q.front();
		q.pop(); int s = find(now);
		if (*(S[s].begin()) != 0) ans[now] = 0;
		else
		{
			for (auto iter = S[s].begin(); iter != S[s].end(); iter++)
			{
				auto iter2 = iter;
				iter2++;
				if (iter2 == S[s].end())
				{
					ans[now] = (*iter) + 1;
				}
				else if ((*iter) + 1 != *iter2)
				{
					ans[now] = (*iter) + 1;
					break;
				}
			}
		}
		if (P[now] >= 0)
		{
			indegree[P[now]]--;
			int p1 = find(P[now]);
			int p2 = find(now);
			if (S[p1].size() > S[p2].size()) swap(p1, p2);
			parent[p1] = p2;
			for (auto iter = S[p1].begin(); iter != S[p1].end(); iter++)
				S[p2].insert(*iter);
			if (indegree[P[now]] == 0)
				q.push(P[now]);
		}
	}
	for (int i = 1; i <= N; i++)
		cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/25549