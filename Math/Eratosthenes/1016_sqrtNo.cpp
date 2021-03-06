#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using ll = long long;
using namespace std;
int main(void)
{
	ll mn, mx, s = 0;
	cin >> mn >> mx;
	vector<bool> arr(mx - mn + 1, false);
	int sqrtx = sqrt(mx);
	for (ll n = 2; n <= sqrtx; n++)
	{
		ll db = n * n;
		ll x = ceil((double)mn / db) * db;
		for (ll i = x; i <= mx; i += db)
			arr[i - mn] = true;
	}
	for (bool a : arr) if (!a) s++;
	cout << s << '\n';
	return 0;
}

// https://www.acmicpc.net/problem/1016