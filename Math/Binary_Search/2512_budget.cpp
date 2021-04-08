#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> budget;
int n, m;
bool canAlloc(int money)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		if (budget[i] > money)
			s += money;
		else
			s += budget[i];

	return (s <= m);
}


int main()
{
	cin >> n; budget.resize(n);
	for (int i = 0; i < n; i++)
		cin >> budget[i];
	cin >> m;
	int l = 0, r = m;
	while (l + 1 < r)
	{
		int mid = (l + r) / 2;
		if (canAlloc(mid))
			l = mid;
		else
			r = mid;
	}
	l = min(l, *max_element(budget.begin(), budget.end()));
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/2512

/*
typical binary_search problem
*/