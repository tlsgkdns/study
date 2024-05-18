#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 200001;
vector<int> adj[MAX];
int N, M, A, cnt[MAX], v[MAX], S;
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		while (true)
		{
			cin >> A;
			if (A == 0) break;
			adj[i].push_back(A);
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> S;
		q.push(S);
		v[S] = 0;
	}
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			if (v[there] >= 0) continue;
			++cnt[there];
			int h = (adj[there].size() % 2 > 0) ? (adj[there].size() / 2) + 1 : (adj[there].size() / 2);
			if (cnt[there] == h)
			{
				v[there] = v[here] + 1;
				q.push(there);
			}
		}
	}
	for (int i = 1; i <= N; i++) cout << v[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/19538