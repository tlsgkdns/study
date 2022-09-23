#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
vector<pair<int, int>> G;
vector<int> tree;
int N, M, A, B;
int arr[2001];
ll ans = 0;
int query(int node, int l, int r, int nl, int nr)
{
	if (nr < l || nl > r) return 0;
	if (nl >= l && nr <= r) return tree[node];
	int m = (nl + nr) / 2;
	return query(node * 2, l, r, nl, m) + query(node * 2 + 1, l, r, m + 1, nr);
}

int update(int node, int l, int r, int idx, int v)
{
	if (idx < l || idx > r) return tree[node];
	if (l == r) return tree[node] = v;
	int m = (l + r) / 2;
	return tree[node] = update(node * 2, l, m, idx, v) + update(node * 2 + 1, m + 1, r, idx, v);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	tree.resize((N + 1) * 4, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		G.push_back({ A, B });
	}
	sort(G.begin(), G.end());
	for (int i = 0; i < M; i++)
	{
		int cur = G[i].second;
		ans += (ll)query(1, cur + 1, N, 1, N);
		update(1, 1, N, cur, ++arr[cur]);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1615