#include <iostream>
#include <vector>

using namespace std;
using ll = unsigned long long int;
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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
	cin >> n >> m;
	control.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> control[i];
		if (control[i] > mx) mx = control[i];
	}
	h = mx * m;
	for (int it = 0; it <= 100; it++)
	{
		mid = (h + l) / 2;
		if (canDo(mid)) h = mid;
		else l = mid + 1;
	}
	cout << mid << '\n';
}

// https://www.acmicpc.net/problem/3079