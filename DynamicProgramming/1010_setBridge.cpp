#include <iostream>
#define lim 30
#define mod 1000000007

using namespace std;
using ll = long long;

ll fac[lim + 1], facinv[lim + 1];

ll power(ll base, int idx)
{
	ll r = 1;
	while (idx)
	{
		if (idx & 1) r = (r * base) % mod;
		base = (base * base) % mod;
		idx >>= 1;
	}
	return r;
}
ll comb(int n, int k)
{
	ll r = (fac[n] * facinv[n - k]) % mod;
	r = (r * facinv[k]) % mod;
	return r;
}
int t;

int main()
{
	cin >> t;
	fac[0] = fac[1] = facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= lim; i++)
		fac[i] = (fac[i - 1] * i) % mod;
	facinv[lim] = power(fac[lim], mod - 2);
	for (int i = lim; i > 2; i--)
		facinv[i - 1] = (facinv[i] * i) % mod;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;
		cout << comb(m, n) << '\n';
	}
}

// https://www.acmicpc.net/problem/1010