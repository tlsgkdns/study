#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100002, INF = 1000000001;
vector<int> tree[MAX * 4];
int arr[MAX], N, M, A, B, C;

vector<int> init(int l, int r, int node)
{
	if (l == r)
	{
		tree[node].push_back(arr[l]);
		return tree[node];
	}
	int m = (l + r) / 2;
	vector<int> L = init(l, m, node * 2), R = init(m + 1, r, node * 2 + 1);
	tree[node].resize(L.size() + R.size());
	merge(L.begin(), L.end(), R.begin(), R.end(), tree[node].begin());
	return tree[node];
}

int query(int s, int e, int l, int r, int node, int k)
{
	if (e < l || s > r) return 0;
	if (l <= s && r >= e) return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
	int m = (s + e) / 2;
	return query(s, m, l, r, node * 2, k) + query(m + 1, e, l, r, node * 2 + 1, k);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	init(1, N, 1);
	while (M--)
	{
		int l = -INF, r = INF;
		cin >> A >> B >> C;
		for (int it = 0; it < 100; it++)
		{
			int m = (l + r) / 2;
			if (query(1, N, A, B, 1, m) >= C) r = m;
			else l = m;
		}
		cout << r << '\n';
	}
}

// https://www.acmicpc.net/problem/7469