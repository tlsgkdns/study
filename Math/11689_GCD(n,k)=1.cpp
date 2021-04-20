#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
using namespace std;

int main()
{
	ll n, p;
	cin >> n;
	p = n;
	for (ll i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			p /= i;
			p *= (i - 1);
		}
		while (n % i == 0) n /= i;
	}
	if (n != 1)
	{
		p /= n;
		p *= (n - 1);
	}
	cout << p << '\n';
}

// https://www.acmicpc.net/problem/11689