#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
int n, m, op, a, b;
int find(int q)
{
	if (parent[q] == q) return q;
	return parent[q] = find(parent[q]);
}
void merge(int n1, int n2)
{
	int p = find(n1); int q = find(n2);
	if (p > q) swap(p, q);
	parent[q] = p;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<string> ans;
	cin >> n >> m;
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++)
	{
		cin >> op >> a >> b;
		if (!op) merge(a, b);
		else ans.push_back((find(a) == find(b)) ? "YES" : "NO");
	}
	for (string a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/1717