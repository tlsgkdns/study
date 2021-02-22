#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, prev, order = 0;
	cin >> n;
	vector<pair<int, int>> v(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		v[i].first = e;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	prev = v[0].first;
	for (int i = 0; i < n; i++)
	{
		if (prev != v[i].first)
		{
			order++;
			prev = v[i].first;
		}
		ans[v[i].second] = order;
	}
	for (int a : ans) cout << a << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/18870

/*
store previous position, sort it and numbering by order it.
*/