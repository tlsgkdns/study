#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int high = 1000000001;
int low = 0;
int n, m;

vector<int> tree;
bool can(int h)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (tree[i] - h > 0) ? tree[i] - h : 0;
		if (sum >= m) break;
	}

	return sum >= m;
}

int srch()
{
	int l = low, h = high;
	for (int it = 0; it < 100; it++)
	{
		int mid = (l + h) / 2;
		if (can(mid))
			l = mid;
		else
			h = mid;
	}

	return l;
}
int main()
{
	cin >> n >> m;
	tree.resize(n);
	for (int i = 0; i < n; i++) cin >> tree[i];

	cout << srch() << endl;
}

// https://www.acmicpc.net/problem/2805