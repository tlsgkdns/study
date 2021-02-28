#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const long long MAX_LL = numeric_limits<long long>::max();
const long long MIN_LL = numeric_limits<long long>::min();

struct RMQ {
	int n;

	vector<long long> rangeMin;
	vector<long long> rangeMax;

	RMQ(const vector<long long>& array) {
		n = array.size();
		rangeMin.resize(n * 4);
		rangeMax.resize(n * 4);
		init(array, 0, n - 1, 1);
	}
	void init(const vector<long long>& array, int left, int right, int node)
	{
		initMin(array, 0, n - 1, 1);
		initMax(array, 0, n - 1, 1);
	}

	long long initMin(const vector<long long>& array, int left, int right, int node)
	{
		if (left == right) return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		long long leftMin = initMin(array, left, mid, node * 2);
		long long rightMin = initMin(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}

	long long initMax(const vector<long long>& array, int left, int right, int node)
	{
		if (left == right) return rangeMax[node] = array[left];
		int mid = (left + right) / 2;
		long long leftMax = initMax(array, left, mid, node * 2);
		long long rightMax = initMax(array, mid + 1, right, node * 2 + 1);
		return rangeMax[node] = max(leftMax, rightMax);
	}

	long long queryMin(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if (nodeRight < left || nodeLeft > right) return MAX_LL;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];

		int mid = (nodeLeft + nodeRight) / 2;
		return min(queryMin(left, right, node * 2, nodeLeft, mid),
			queryMin(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	long long queryMax(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if (nodeRight < left || nodeLeft > right) return MIN_LL;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMax[node];

		int mid = (nodeLeft + nodeRight) / 2;
		return max(queryMax(left, right, node * 2, nodeLeft, mid),
			queryMax(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
};
int main(void)
{
	vector<long long> v;
	vector<pair<int, int>> q;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		v.push_back(e);
	}
	for (int j = 0; j < m; j++)
	{
		int si, bi;
		cin >> si >> bi;
		q.push_back(make_pair(si, bi));
	}

	RMQ r(v);
	for (pair<int, int> index : q)
		cout << r.queryMin(index.first - 1, index.second - 1, 1, 0, n - 1) <<
		" " << r.queryMax(index.first - 1, index.second - 1, 1, 0, n - 1) << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/2357
/*
standard segment-tree problem.
*/