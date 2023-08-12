#include <iostream>

using namespace std;
using ll = long long;
ll N, Q, X, Y, A, B;
ll arr[100003], tree[400012];
ll init(int l, int r, int idx)
{
	if (l == r) return tree[idx] = arr[l];
	int m = (l + r) / 2;
	return tree[idx] = init(l, m, idx * 2) + init(m + 1, r, idx * 2 + 1);
}

ll s(int l, int r, int nl, int nr, int idx)
{
	if (r < nl || nr < l) return 0;
	if (l <= nl && nr <= r) return tree[idx];
	int m = (nl + nr) / 2;
	return s(l, r, nl, m, idx * 2) + s(l, r, m + 1, nr, idx * 2 + 1);
}

ll u(int l, int r, int node, int idx, ll v)
{
	if (idx < l || idx > r) return tree[node];
	if (l == r) return tree[node] = v;
	int m = (l + r) / 2;
	return tree[node] = u(l, m, node * 2, idx, v) + u(m + 1, r, node * 2 + 1, idx, v);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	init(1, N, 1);
	while (Q--)
	{
		cin >> X >> Y >> A >> B;
		if (X > Y) swap(X, Y);
		cout << s(X, Y, 1, N, 1) << '\n';
		u(1, N, 1, A, B);
	}
}

// https://www.acmicpc.net/problem/1275