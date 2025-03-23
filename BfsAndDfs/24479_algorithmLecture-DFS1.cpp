#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R, A, B, now = 1;
vector<int> adj[100001];
bool v[100001];
int ans[100001];
void dfs(int here)
{
	ans[here] = now++;
	for (const int& there : adj[here])
	{
		if (v[there]) continue;
		v[there] = true;
		dfs(there);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());
	v[R] = true;
	dfs(R);
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/24479