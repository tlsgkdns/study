#include <iostream>
using namespace std;
using ll = long long;

ll A, B;
ll gcd(ll a, ll b)
{
	if (a < b) return gcd(b, a);
	while (b != 0)
	{
		ll tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	ll g = gcd(A, B);
	for (ll i = 1; i <= g; i++)
		cout << 1;
	cout << '\n';
}

// https://www.acmicpc.net/problem/1850