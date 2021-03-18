#include <iostream>
using namespace std;
using ll = long long;
int n, k;
int bSearch(ll l, ll r)
{
	if (l > r) return l;
	ll mid = (l + r) / 2;
	ll cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += (mid / i < n) ? mid / i : n;
	if (cnt < k) return bSearch(mid + 1, r);
	else return bSearch(l, mid - 1);
}
int main()
{
	cin >> n >> k;
	cout << bSearch(1, k) << '\n';
}

// https://www.acmicpc.net/problem/1300

/*
Hard to came up the idea.
This code referred to google.
I learned from Google and understood how this code works.
Next time I met a similar problem. I will apply this way.
*/