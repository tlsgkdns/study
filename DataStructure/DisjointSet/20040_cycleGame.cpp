#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, rk;
int find(int u)
{
	if (u == parent[u]) return u;

	return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u == v) return;
	if (rk[v] < rk[u]) swap(u, v);
	parent[u] = v;
	if (rk[v] == rk[u]) ++rk[v];
	return;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	int n, m, a, b, ans = 0;
	cin >> n >> m;
	parent.resize(n + 1);
	rk.resize(n + 1, 0);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		if (find(a) == find(b))
		{
			ans = i;
			break;
		}
		merge(a, b);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/20040