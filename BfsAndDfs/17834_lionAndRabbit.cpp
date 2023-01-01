#include <iostream>
#include <queue>
using namespace std;

bool v[50001][2];
int N, M, U, V, O = 0, E = 0;
vector<int> adj[50001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	queue<pair<int, bool>> q;
	q.push({ 1, false });
	v[1][0] = true;
	while (!q.empty())
	{
		int here = q.front().first;
		bool odd = q.front().second;
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			if (v[there][!odd]) continue;
			v[there][!odd] = true;
			q.push({ there, !odd });
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (v[i][1] && v[i][0]) continue;
		if (v[i][0]) ++E;
		else if (v[i][1]) ++O;
	}
	cout << E * O * 2 << '\n';
}

// https://www.acmicpc.net/problem/17834