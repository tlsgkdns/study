#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
int N, A[100001], M, C, L, R;
pii T[400004];

pii init(int l, int r, int node)
{
	if (l == r) return T[node] = { A[l], 0 };
	int m = (l + r) / 2;
	pii left = init(l, m, node * 2);
	pii right = init(m + 1, r, node * 2 + 1);
	vector<int> arr = { left.first, left.second, right.first, right.second };
	sort(arr.begin(), arr.end());
	return T[node] = { arr[3], arr[2] };
}
pii query(int l, int r, int nl, int nr, int node)
{
	if (nl > r || nr < l) return { 0, 0 };
	if (nr <= r && nl >= l) return T[node];
	int m = (nl + nr) / 2;
	pii left = query(l, r, nl, m, node * 2);
	pii right = query(l, r, m + 1, nr, node * 2 + 1);
	vector<int> arr = { left.first, left.second, right.first, right.second };
	sort(arr.begin(), arr.end());
	return { arr[3], arr[2] };
}
pii update(int id, int v, int node, int nl, int nr)
{
	if (id < nl || nr < id) return T[node];
	if (nl == nr) return T[node] = { v, 0 };
	int m = (nl + nr) / 2;
	pii left = update(id, v, node * 2, nl, m);
	pii right = update(id, v, node * 2 + 1, m + 1, nr);
	vector<int> arr = { left.first, left.second, right.first, right.second };
	sort(arr.begin(), arr.end());
	return T[node] = { arr[3], arr[2] };
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	init(0, N - 1, 1);
	cin >> M;
	while (M--)
	{
		cin >> C >> L >> R;
		if (C == 1)
		{
			update(L - 1, R, 1, 0, N - 1);
		}
		else
		{
			pii p = query(L - 1, R - 1, 0, N - 1, 1);
			cout << p.first + p.second << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/17408