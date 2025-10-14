#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int N, M, R, U, V;
vector<int> adj[100001];
int v[100001];

void solve(int here, int d)
{
	if (v[here] >= 0) return;
	v[here] = d;
	for (int i = 0; i < adj[here].size(); i++)
		solve(adj[here][i], d + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}
	for (int i = 1; i <= N; i++)
		sort(adj[i].begin(), adj[i].end());
	solve(R, 0);
	for (int i = 1; i <= N; i++) cout << v[i] << '\n';
}

// https://www.acmicpc.net/problem/24481