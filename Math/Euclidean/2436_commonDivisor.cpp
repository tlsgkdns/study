#include <iostream>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b)
{
	if (a < b) return gcd(b, a);
	ll tmp;
	while (b != 0)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	ll a, b, num, ansA = 100000001, ansB = 10000001;
	cin >> a >> b;
	num = (b / a);
	for (int n = 1; n * n <= num; n++)
	{
		if (num % n != 0) continue;
		ll opp = (num / n);
		if (gcd(n, opp) != 1) continue;
		ll s = (opp + n) * a;
		if (ansA + ansB > s)
		{
			ansA = n * a;
			ansB = opp * a;
		}
	}
	cout << ansA << " " << ansB << '\n';
}

// https://www.acmicpc.net/problem/2436