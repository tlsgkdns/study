#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> tree, arr;
int N, ans = 0;
int init(int left, int right, int node)
{
	if (left == right) return tree[node] = left;
	int mid = (left + right) / 2;
	int l = init(left, mid, node * 2);
	int r = init(mid + 1, right, node * 2 + 1);
	return tree[node] = ((arr[l] < arr[r]) ? l : r);
}

int query(int left, int right, int nodeLeft, int nodeRight, int node)
{
	if (nodeRight < left || right < nodeLeft) return -1;
	if (left <= nodeLeft && nodeRight <= right) return tree[node];
	int mid = (nodeLeft + nodeRight) / 2;
	int l = query(left, right, nodeLeft, mid, node * 2);
	int r = query(left, right, mid + 1, nodeRight, node * 2 + 1);
	if (l == -1) return r;	else if (r == -1)  return l;
	else return ((arr[l] < arr[r]) ? l : r);
}

void solve(int left, int right)
{
	if (left > right) return;
	int idx = query(left, right, 0, N - 1, 1);
	ans = max(ans, (right - left + 1) * arr[idx]);
	solve(left, idx - 1);
	solve(idx + 1, right);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; arr.resize(N); tree.resize(4 * N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	init(0, N - 1, 1);
	solve(0, N - 1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1725