#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, A, B, v[501], ans = 0;
vector<int> adj[501];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	queue<int> q;
	memset(v, -1, sizeof(v));
	q.push(1); v[1] = 0;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			if (v[there] >= 0) continue;
			v[there] = v[here] + 1;
			ans++;
			if (v[there] < 2) q.push(there);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5567