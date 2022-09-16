#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 500001;
vector<int> skills, tree, ans;
int R[MAX], d[MAX];
int N, SK;

int init(int node, int l, int r)
{
	if (l == r) return tree[node] = d[l];
	int m = (l + r) / 2;
	return tree[node] = init(node * 2, l, m) + init(node * 2 + 1, m + 1, r);
}
int update(int node, int s, int e, int idx, int val)
{
	if (idx < s || idx > e) return tree[node];
	if (s == e) return tree[node] = val;
	int m = (s + e) / 2;
	return tree[node] = update(node * 2, s, m, idx, val) + update(node * 2 + 1, m + 1, e, idx, val);
}
int query(int node, int s, int e, int nl, int nr)
{
	if (nl > e || nr < s) return 0;
	if (nr <= e && nl >= s) return tree[node];
	int m = (nl + nr) / 2;
	return query(node * 2, s, e, nl, m) + query(node * 2 + 1, s, e, m + 1, nr);
}
int getIdx(int r)
{
	return lower_bound(skills.begin(), skills.end(), r) - skills.begin();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; tree.resize(N * 4);
	for (int i = 0; i < N; i++)
	{
		cin >> R[i];
		skills.push_back(R[i]);
	}
	sort(skills.begin(), skills.end());
	init(1, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		int t = getIdx(R[i]);
		int a = query(1, t, N - 1, 0, N - 1);
		ans.push_back(a + 1);
		update(1, 0, N - 1, t, ++d[t]);
	}
	for (int i = 0; i < N; i++) cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/2517