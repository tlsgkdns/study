#include <iostream>

using namespace std;

int N, P[1000001], T[4000001];
long long ans = 0;
void update(int node, int l, int r, int val, int idx)
{
	if (idx < l || idx > r) return;
	T[node] += val;
	if (l == r) return;
	int m = (l + r) / 2;
	update(2 * node, l, m, val, idx);
	update(2 * node + 1, m + 1, r, val, idx);
}
int query(int l, int r, int s, int e, int node)
{
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return T[node];
	int m = (s + e) / 2;
	return query(l, r, s, m, node * 2) + query(l, r, m + 1, e, node * 2 + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = N - 1; i >= 0; i--) cin >> P[i];
	for (int i = 0; i < N; i++)
	{
		ans += query(0, P[i], 0, N, 1);
		update(1, 0, N, 1, P[i]);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10090