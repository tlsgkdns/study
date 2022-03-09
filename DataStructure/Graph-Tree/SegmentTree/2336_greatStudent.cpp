#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> tree;
const int INF = 1000000000, MAX = 500001;
int N, sc;
class student
{
public:
	int x = 0, y = 0, z = 0;
	student() {}
	student(int _x, int _y, int _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
	bool operator<(const student& s) const
	{
		return x < s.x;
	}
};
student arr[MAX];
int update(int node, int target, int s, int e, int v)
{
	if (target > e || target < s) return tree[node];
	if (s == e) return tree[node] = v;
	int m = (s + e) / 2;
	tree[node] = min(update(node * 2, target, s, m, v), update(node * 2 + 1, target, m + 1, e, v));
	return tree[node];
}

int query(int node, int l, int r, int s, int e)
{
	if (l > e || r < s) return INF;
	if (l <= s && e <= r) return tree[node];
	int m = (s + e) / 2;
	return min(query(node * 2, l, r, s, m), query(node * 2 + 1, l, r, m + 1, e));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; tree.resize(N * 4, INF);
	for (int i = 0; i < N; i++)
	{
		cin >> sc;
		arr[--sc].x = i;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> sc;
		arr[--sc].y = i;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> sc;
		arr[--sc].z = i;
	}
	sort(arr, arr + N);
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int y = arr[i].y;
		int z = arr[i].z;
		if (query(1, 0, y, 0, N - 1) > z) ans++;
		update(1, y, 0, N - 1, z);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2336