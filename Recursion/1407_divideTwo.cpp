#include <iostream>
using namespace std;
using ll = long long;
ll A, B;

ll solve(ll n, ll d)
{
	if (n == 0) return 0;
	ll s = (n % 2 > 0) ? (n / 2 + 1) : n / 2;
	return solve(n / 2, d * 2L) + d * s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	cout << solve(B, 1) - solve(A - 1, 1) << '\n';
}

// https://www.acmicpc.net/problem/1407