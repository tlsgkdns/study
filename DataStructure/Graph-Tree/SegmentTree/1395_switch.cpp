#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int tree[400004];
int N, M, O, S, T;
bool lazy[400004];
void updateLazy(int node, int s, int e)
{
	if (!lazy[node]) return;
	tree[node] = (e - s + 1) - tree[node];
	if (s != e)
	{
		lazy[node * 2] = !lazy[node * 2];
		lazy[node * 2 + 1] = !lazy[node * 2 + 1];
	}
	lazy[node] = false;
}
void update(int node, int s, int e, int l, int r)
{
	updateLazy(node, s, e);
	if (l > e || r < s) return;
	if (l <= s && e <= r)
	{
		tree[node] = (e - s + 1) - tree[node];
		if (s != e)
		{
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return;
	}
	int m = (s + e) / 2;
	update(node * 2, s, m, l, r);
	update(node * 2 + 1, m + 1, e, l, r);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(int node, int s, int e, int l, int r)
{
	updateLazy(node, s, e);
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return tree[node];
	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> O >> S >> T;
		if (O == 0) update(1, 1, N, S, T);
		else cout << query(1, 1, N, S, T) << '\n';
	}
}

// https://www.acmicpc.net/problem/1395