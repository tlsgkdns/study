#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& adj, vector<bool>& v, vector<int>& depth,
	int n, int d)
{
	v[n] = true;
	depth[n] = d;
	for (int i = 0; i < adj[n].size(); i++)
	{
		int next = adj[n][i];
		if (v[next]) continue;
		DFS(adj, v, depth, next, d + 1);
	}
}
int LCA(vector<int>& parent, vector<int>& depth, int na, int nb)
{
	if (na == nb) return na;
	if (depth[na] == depth[nb]) return LCA(parent, depth, parent[na], parent[nb]);
	else if (depth[na] > depth[nb]) return LCA(parent, depth, parent[na], nb);
	else return LCA(parent, depth, na, parent[nb]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	vector<int> ans;
	for (int t = 0; t < T; t++)
	{
		int N, A, B, N1, N2, r = -1;
		cin >> N;
		vector<vector<int>> adj(N + 1);
		vector<int> parent(N + 1), depth(N + 1, 0);
		vector<bool> v(N + 1, false), chk(N + 1, false);
		for (int i = 0; i < N - 1; i++)
		{
			cin >> A >> B;
			adj[A].push_back(B);
			adj[B].push_back(A);
			parent[B] = A;
			chk[B] = true;
		}
		for (int i = 1; i <= N; i++)
			if (!chk[i])
			{
				r = i;
				break;
			}
		cin >> N1 >> N2;
		DFS(adj, v, depth, r, 0);
		ans.push_back(LCA(parent, depth, N1, N2));
	}
	for (int a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/3584