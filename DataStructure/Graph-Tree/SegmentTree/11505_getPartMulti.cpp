#include <iostream>
#include <vector>
#define div 1000000007

using namespace std;
using ll = long long;

vector<ll> tree, arr, ans;
int n, m, k;
ll init(int l, int r, int node)
{
	if (l == r)  return tree[node] = arr[l];
	int mid = (l + r) / 2;
	ll ln = init(l, mid, node * 2) % div;
	ll rn = init(mid + 1, r, node * 2 + 1) % div;

	return tree[node] = (ln * rn) % div;
}

ll query(int left, int right, int nl, int nr, int node)
{
	if (nl > right || nr < left) return 1;
	if (nl >= left && nr <= right) return tree[node] % div;
	int mid = (nl + nr) / 2;
	ll l = query(left, right, nl, mid, node * 2) % div;
	ll r = query(left, right, mid + 1, nr, node * 2 + 1) % div;
	return (l * r) % div;
}
ll update(int left, int right, int node, ll val, int id)
{
	if (id < left || id > right) return tree[node] % div;
	if (left == right)
		return tree[node] = val;
	int mid = (left + right) / 2;
	return tree[node] = update(left, mid, node * 2, val, id) % div *
		update(mid + 1, right, node * 2 + 1, val, id) % div;
}

int main()
{
	cin >> n >> m >> k;
	tree.resize(n * 4);
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	init(0, n - 1, 1);
	for (int i = 0; i < m + k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(0, n - 1, 1, c, b - 1);
		else ans.push_back(query(b - 1, c - 1, 0, n - 1, 1) % div);
	}
	for (auto a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/11505