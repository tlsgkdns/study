#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
int main()
{
	int n, m;
	cin >> n;
	ll t = 0, ans = 0;
	vector<int> h;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		h.push_back(a);
	}
	m = h[0];
	for (int i = 1; i < n; i++)
	{
		if (m < h[i])
		{
			ans = max(ans, t);
			m = h[i];
			t = 0;
		}
		else
			t++;
	}
	ans = max(ans, t);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14659

/*
basic greedy problem
*/