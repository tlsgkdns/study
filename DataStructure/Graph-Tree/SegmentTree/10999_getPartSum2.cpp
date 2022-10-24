#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> tree, lazy, arr, ans;
int N, M, K, A, B, C;
ll D;
void init(int node, int s, int e)
{
	if (s == e)
	{
		tree[node] = arr[s];
		return;
	}
	int m = (s + e) / 2;
	init(node * 2, s, m); init(node * 2 + 1, m + 1, e);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void updateLazy(int node, int s, int e)
{
	if (lazy[node] == 0) return;
	tree[node] += (e - s + 1) * lazy[node];
	if (s != e)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}
void updateRange(int node, int s, int e, int l, int r, ll diff)
{
	updateLazy(node, s, e);
	if (l > e || r < s) return;
	if (l <= s && e <= r)
	{
		tree[node] += (e - s + 1) * diff;
		if (s != e)
		{
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	int m = (s + e) / 2;
	updateRange(node * 2, s, m, l, r, diff);
	updateRange(node * 2 + 1, m + 1, e, l, r, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll query(int node, int s, int e, int l, int r)
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
	cin >> N >> M >> K;
	tree.resize(N * 4); lazy.resize(N * 4); arr.resize(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	init(1, 0, N - 1);
	for (int i = 0; i < M + K; i++)
	{
		cin >> A >> B >> C;
		if (A == 1)
		{
			cin >> D;
			updateRange(1, 0, N - 1, B - 1, C - 1, D);
		}
		else
			ans.push_back(query(1, 0, N - 1, B - 1, C - 1));
	}
	for (ll a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/10999