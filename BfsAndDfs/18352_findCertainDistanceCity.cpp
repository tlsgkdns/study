#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 300001;
vector<int> adj[MAX];
int N, M, K, X, A, B;
int v[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
	}
	queue<int> q;
	q.push(X);
	v[X] = 0;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			if (v[there] >= 0) continue;
			v[there] = v[here] + 1;
			q.push(there);
		}
	}
	bool no = true;
	for (int i = 1; i <= N; i++)
	{
		if (v[i] == K)
		{
			cout << i << '\n';
			no = false;
		}
	}
	if (no) cout << -1 << '\n';
}

// https://www.acmicpc.net/problem/18352