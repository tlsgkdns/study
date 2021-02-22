#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tree
{
	vector<int> content;
	vector<vector<int>> seg;
	int n;
	tree(vector<int> arr)
	{
		n = arr.size();
		content = arr;
		seg.resize(n * 4);
		vector<int> r = init(0, n - 1, 1);
	}

	vector<int> init(int left, int right, int node)
	{
		if (left == right)
		{
			vector<int> a;
			a.push_back(content[left]);
			return seg[node] = a;
		}

		int mid = (left + right) / 2;

		seg[node] = merge(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));

		return seg[node];
	}

	int query(int start, int end, int left, int right, int node, int k)
	{
		if (end < left || start > right) return 0;
		if (left <= start && right >= end) return seg[node].end() - upper_bound(seg[node].begin(), seg[node].end(), k);

		int mid = (start + end) / 2;

		return query(start, mid, left, right, node * 2, k) + query(mid + 1, end, left, right, node * 2 + 1, k);
	}

	vector<int> merge(vector<int> a, vector<int> b)
	{
		int n = a.size() + b.size();
		vector<int> c(n);
		int ai = 0, bi = 0;
		for (int ci = 0; ci < n;)
		{
			if (a[ai] < b[bi])
			{
				c[ci] = a[ai];
				ai++;
			}
			else {
				c[ci] = b[bi];
				bi++;
			}

			ci++;
			if (bi == b.size())
				while (ai < a.size())
				{
					c[ci] = a[ai];
					ai++; ci++;
				}
			else if (ai == a.size())
				while (bi < b.size())
				{
					c[ci] = b[bi];
					bi++; ci++;
				}
		}

		return c;
	}
};


int main(void)
{
	int n, tmp;
	vector<int> v;
	vector<int> ans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	tree t(v);

	int qn;
	cin >> qn;
	for (int j = 0; j < qn; j++)
	{
		vector<int> q;
		int tmp;
		for (int k = 0; k < 3; k++)
		{
			cin >> tmp;
			q.push_back(tmp);
		}
		ans.push_back(t.query(0, n - 1, q[0] - 1, q[1] - 1, 1, q[2]));
	}

	for (int a : ans) cout << a << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/13537

/*
First, I solve segementTree.
But, it turns out "Times out"
So, I googled about another tree.
and used MergeSort-Tree.
*/