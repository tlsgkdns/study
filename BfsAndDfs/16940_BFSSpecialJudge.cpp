#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> adj[100001];
int N, A, B, T[100001], D[100001], idx = 1, ans = 1;
bool v[100001];
bool cmp(int a, int b)
{
	return D[a] < D[b];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> T[i];
		D[T[i]] = i;
	}
	for (int i = 1; i <= N; i++)
		sort(adj[i].begin(), adj[i].end(), cmp);
	if (T[0] != 1) ans = 0;
	else
	{
		queue<int> q;
		v[1] = true;
		q.push(1);
		while (!q.empty())
		{
			int here = q.front();
			q.pop();
			for (int i = 0; i < adj[here].size(); i++)
			{
				int there = adj[here][i];
				if (v[there]) continue;
				v[there] = true;
				if (there != T[idx])
				{
					ans = 0;
					break;
				}
				++idx;
				q.push(there);
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16940