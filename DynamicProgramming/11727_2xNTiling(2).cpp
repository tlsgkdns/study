#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> c;

ll tiling(int t)
{
	ll& r = c[t];
	if (r != -1) return r;

	r = (tiling(t - 1) + 2 * tiling(t - 2)) % 10007;

	return r;
}
int main()
{
	int n;
	cin >> n;
	c.resize(n + 1, -1);
	c[0] = c[1] = 1;
	cout << tiling(n) % 10007 << '\n';
}
// https://www.acmicpc.net/problem/11727