#include <iostream>
#include <vector>
using namespace std;

int N, M, a, p;
vector<vector<bool>> adj;
vector<int> group;
vector<bool> v;
int find(int a)
{
	if (group[a] == a) return a;

	return group[a] = find(group[a]);
}
void merge(int a, int b)
{
	int p = find(a);
	int q = find(b);
	if (p < q) swap(p, q);
	group[p] = q;
}
void dfs(int here)
{
	for (int i = 0; i < N; i++)
	{
		if (!adj[here][i]) continue;
		merge(here, i);
		if (v[i]) continue;
		v[i] = true;
		dfs(i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> M;
	adj.resize(N, vector<bool>(N, false));
	v.resize(N, false);	group.resize(N);
	for (int i = 0; i < N; i++)
		group[i] = i;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> a;
			adj[i][j] = a;
			adj[j][i] = a;
		}
	for (int i = 0; i < N; i++)
		if (!v[i])
		{
			v[i] = true;
			dfs(i);
		}
	bool ans = true;
	int g = -1;
	for (int i = 0; i < M; i++)
	{
		cin >> p;
		if (g == -1) g = find(p - 1);
		else if (find(p - 1) != g)
		{
			ans = false;
			break;
		}
	}
	if (ans) cout << "YES\n";
	else cout << "NO\n";
}
// https://www.acmicpc.net/problem/1976