#include <iostream>
#include <vector>
#include <limits>
using namespace std;
using ll = long long;
vector<ll> control;
ll n, m, h, l = 0, mid, mx = -1;
bool canDo(ll time)
{
	ll s = 0;
	for (int i = 0; i < n; i++)
		s += time / control[i];
	return s >= m;
}
int main()
{
	h = numeric_limits<ll>::max();
	cin >> n >> m;
	control.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> control[i];
		if (control[i] > mx) mx = control[i];
	}
	h = m * mx;
	for (int it = 0; it <= 100; it++)
	{
		mid = (h + l) / 2;
		if (canDo(mid)) h = mid;
		else l = mid + 1;
	}
	cout << mid << '\n';
}

// https://www.acmicpc.net/problem/3079
/*
I solved it at the other site, 
But link's site test case was harder than other site.
OverFlow was annoying. in other words, select initial "h" value was hard.
*/