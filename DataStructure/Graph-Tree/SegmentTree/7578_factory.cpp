#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
using ll = long long;
ll n, ans = 0;
unordered_map<int, int> m;

struct Fenwick
{
	vector<int> tree;
	Fenwick(int n) : tree(n + 1) {}
	ll sum(int pos)
	{
		++pos;
		ll ret = 0;
		while (pos > 0)
		{
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}

	void add(int pos, int val)
	{
		++pos;
		while (pos < tree.size())
		{
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		m[a] = i;
	}
	Fenwick tree(n + 1);
	for (int i = 0; i < n; i++)
	{
		int b; cin >> b;
		int idx = m[b];
		ans += tree.sum(n) - tree.sum(idx);
		tree.add(idx, 1);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/7578