#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int M = numeric_limits<int>::max();

class minimum
{
public:
	minimum(vector<int> a)
	{
		data = a;
		n = a.size();
		tree.resize(n * 4);
		init(0, n - 1, 1);
	}

	int init(int start, int end, int node)
	{
		if (start == end) return tree[node] = data[end];
		int mid = (start + end) / 2;

		return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
	}

	int query(int nodeLeft, int nodeRight, int start, int end, int node)
	{
		if (nodeLeft >= start && nodeRight <= end) return tree[node];
		if (nodeLeft > end || nodeRight < start) return M;

		int mid = (nodeLeft + nodeRight) / 2;

		return min(query(nodeLeft, mid, start, end, node * 2)
			, query(mid + 1, nodeRight, start, end, node * 2 + 1));
	}
private:
	vector<int> data;
	vector<int> tree;
	int n;
};


int main()
{
	int n, m, tmp;
	cin >> n >> m;
	vector<int> input;
	vector<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		input.push_back(tmp);
	}

	minimum t(input);
	int a, b;
	for (int j = 0; j < m; j++)
	{
		cin >> a >> b;
		q.push_back(make_pair(a, b));
	}

	for (pair<int, int> p : q)
		cout << t.query(0, n - 1, p.first - 1, p.second - 1, 1) << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/10868

/*
basic of segmentTree
*/