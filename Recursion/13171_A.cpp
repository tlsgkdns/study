#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;
ll A, X;

ll solve(ll n)
{
	if (n == 0) return 1;
	if (n == 1) return A;
	ll h = solve(n / 2) % MOD;
	h *= h; h %= MOD;
	if (n % 2 > 0) return (h * (A % MOD)) % MOD;
	return h;
}
int main()
{
	cin >> A >> X;
	cout << solve(X) << '\n';
}

// https://www.acmicpc.net/problem/13171