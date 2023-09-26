#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> adj[1001];
int N, M, A, B, C, D[1001], v[1001];
bool f = false;
void dfs(int here, long long s, int dst)
{
	if (f) return;
	if (dst == here)
	{
		f = true;
		cout << s << '\n';
	}
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		if (v[there]) continue;
		v[there] = true;
		dfs(there, s + adj[here][i].second, dst);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });

	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		f = false;
		memset(v, false, sizeof(v));
		v[A] = true;
		dfs(A, 0, B);
	}
}
// https://www.acmicpc.net/problem/1240