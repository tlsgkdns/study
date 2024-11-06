#include <iostream>

using namespace std;
using ll = long long;
ll T, A, B;

ll gcd(ll a, ll b)
{
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> A >> B;
		cout << (A * B) / gcd(A, B) << '\n';
	}
}

// https://www.acmicpc.net/problem/1934