#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool v[100][2];
int N, M, A, B, ans = 0, mid = 0;
vector<int> adj[100][2];
int dfs(int here, int d)
{
	int ret = 0;
	for (int i = 0; i < adj[here][d].size(); i++)
	{
		int there = adj[here][d][i];
		if (v[there][d]) continue;
		v[there][d] = true;
		ret += dfs(there, d) + 1;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	mid = (N + 1) / 2;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A][0].push_back(B);
		adj[B][1].push_back(A);
	}
	for (int i = 1; i <= N; i++)
	{
		memset(v, false, sizeof(v));
		v[i][0] = true; v[i][1] = true;
		ans += (dfs(i, 0) >= mid || dfs(i, 1) >= mid);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2617