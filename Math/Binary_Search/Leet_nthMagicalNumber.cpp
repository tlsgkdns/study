#include <iostream>
using namespace std;

using ll = long long;
class Solution
{
public:
	ll gcd(ll a, ll b)
	{
		while (b != 0)
		{
			ll r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
	ll lcm(ll a, ll b)
	{
		return (a * b) / gcd(a, b);
	}
	int nthMagicalNumber(int n, int a, int b)
	{
		if (a > b) return nthMagicalNumber(n, b, a);
		ll l = 0, r = numeric_limits<ll>::max();
		while (l < r)
		{
			ll m = (l + r) / 2;
			ll cnt = (m / a) + (m / b) - (m / lcm(a, b));
			if (cnt >= n)
				r = m;
			else
				l = m + 1;
		}
		return l % 1000000007;
	}
};

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	Solution s;
	cout << s.nthMagicalNumber(n, a, b) << '\n';
}

// https://leetcode.com/problems/nth-magical-number/