#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<vector<ll>> v;
ll n, l = 0, r = numeric_limits<int>::max();
ll f(ll num)
{
	ll s = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i][0] > num) continue;
		if (v[i][1] < num)
			s += ((v[i][1] - v[i][0]) / v[i][2]) + 1;
		else
			s += ((num - v[i][0]) / v[i][2]) + 1;
	}
	return s;
}
int main()
{
	cin >> n; v.resize(n, vector<ll>(3));
	for (int i = 0; i < n; i++)
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	for (int it = 0; it < 100; it++)
	{
		ll mid = (l + r) / 2;
		ll s = f(mid);
		if (s % 2 == 0) l = mid;
		else r = mid;
	}
	ll sub = f(r) - f(l);
	if (sub % 2 != 1) cout << "NOTHING" << '\n';
	else cout << r << " " << sub << '\n';
}
// https://www.acmicpc.net/problem/1637