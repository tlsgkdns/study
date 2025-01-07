#include <iostream>

using namespace std;
using ll = unsigned long long;
ll s = 1, m = 0, A[10], N;
ll gcd(ll a, ll b)
{
	if (a < b) swap(a, b);
	while (b > 0)
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
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	m = A[0];
	for (int i = 1; i < N; i++)
	{
		ll l = (A[i] * m) / gcd(m, A[i]);
		s = (s * (l / m)) + (l / A[i]);
		m = l;
	}
	ll g = gcd(m, s);
	cout << (m / g) << "/" << (s / g) << '\n';
}

// https://www.acmicpc.net/problem/2090