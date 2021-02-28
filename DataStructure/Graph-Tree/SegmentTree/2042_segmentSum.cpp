#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
using ll = long long;


class Tree
{
private:
	vector<ll> data;
	vector<ll> tree;
	int n;

public:
	Tree(vector<ll> d)
	{
		n = d.size();
		data.resize(n + 1);
		data = d;
		tree.resize(n * 4);
		init(1, 0, n - 1);
	}

	ll init(ll node, int left, int right)
	{
		if (left == right) return tree[node] = data[left];
		int mid = (left + right) / 2;

		return tree[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
	}

	ll query(int left, int right, int nodeLeft, int nodeRight, ll node)
	{
		if (nodeLeft > right || nodeRight < left)
			return 0;
		if (nodeRight <= right && nodeLeft >= left)
			return tree[node];
		int mid = (nodeLeft + nodeRight) / 2;

		return query(left, right, nodeLeft, mid, node * 2) + query(left, right, mid + 1, nodeRight, node * 2 + 1);
	}

	ll update(int id, ll v, int node, int nodeLeft, int nodeRight)
	{
		if (id < nodeLeft || nodeRight < id)
			return tree[node];
		if (nodeLeft == nodeRight)
			return tree[node] = v;
		int mid = (nodeLeft + nodeRight) / 2;

		return tree[node] = update(id, v, node * 2, nodeLeft, mid) + update(id, v, node * 2 + 1, mid + 1, nodeRight);
	}
	ll update(int pos, ll s)
	{
		return update(pos - 1, s, 1, 0, n - 1);
	}

	ll query(int left, int right)
	{
		return query(left - 1, right - 1, 0, n - 1, 1);
	}
};

int main()
{
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> v(n);
	vector<ll> ans;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	Tree t(v);

	for (int j = 0; j < m + k; j++)
	{
		ll i1, i2, i3;
		cin >> i1 >> i2 >> i3;
		if (i1 == 1)
			t.update(i2, i3);
		if (i1 == 2)
			ans.push_back(t.query(i2, i3));
	}

	for (ll a : ans)
		cout << a << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/2042

/*
my first segmentTree Problem
*/