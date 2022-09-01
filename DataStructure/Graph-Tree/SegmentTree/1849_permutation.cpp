#include <iostream>
#include <vector>
using namespace std;

int N, X, V;
vector<int> tree, ans;
int init(int node, int s, int e)
{
	if (s == e) return tree[node] = 1;
	int m = (s + e) / 2;
	return tree[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}

void update(int node, int s, int e, int idx, int diff)
{
	if (idx < s || idx > e) return;
	tree[node] += diff;
	if (s != e)
	{
		int m = (s + e) / 2;
		update(node * 2, s, m, idx, diff);
		update(node * 2 + 1, m + 1, e, idx, diff);
	}
}
int query(int node, int s, int e, int K)
{
	if (s == e) return s;
	int m = (s + e) / 2;
	int l = tree[node * 2];
	if (l > K) return query(node * 2, s, m, K);
	return query(node * 2 + 1, m + 1, e, K - l);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	tree.resize(N * 4); ans.resize(N + 1);
	init(1, 1, N);
	for (int i = 1; i <= N; i++)
	{
		cin >> X;
		V = query(1, 1, N, X);
		ans[V] = i;
		update(1, 1, N, V, -1);
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/1849