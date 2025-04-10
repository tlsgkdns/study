#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int A, B, N, M, a, b, v[1001];
queue<int> q;
vector<int> adj[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> A >> B;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	q.push(A);
	v[A] = 0;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int& there : adj[here])
		{
			if (v[there] >= 0) continue;
			v[there] = v[here] + 1;
			q.push(there);
		}
	}
	cout << v[B] << '\n';
}


// https://www.acmicpc.net/problem/14496