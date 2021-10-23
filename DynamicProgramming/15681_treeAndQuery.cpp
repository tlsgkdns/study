#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
vector<vector<int>> tree;
vector<bool> v;
int N, R, Q, U, V;
int dfs(int cur)
{
	for (int i = 0; i < tree[cur].size(); i++)
	{
		int next = tree[cur][i];
		if (v[next]) continue;
		v[next] = true;
		dp[cur] += dfs(next);
	}
	return dp[cur];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> R >> Q;
	tree.resize(N + 1); dp.resize(N + 1, 1);
	v.resize(N + 1, false);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> U >> V;
		tree[U].push_back(V);
		tree[V].push_back(U);
	}
	v[R] = true;
	dfs(R);
	int r;
	vector<int> ans;
	for (int q = 0; q < Q; q++)
	{
		cin >> r;
		ans.push_back(dp[r]);
	}
	for (int a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/15681