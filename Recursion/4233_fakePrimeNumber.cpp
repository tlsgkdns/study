#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

ll P, A;

ll solve(ll p, ll a)
{
	if (p == 0) return 1;
	if (p == 1) return a;
	ll h = solve(p / 2, a); h *= h;
	h %= P;
	if (p % 2 > 0) return (h * a) % P;
	return h;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> P >> A;
		if (P == 0 && A == 0) break;
		bool prime = true;
		for (int i = 2; i <= sqrt(P); i++)
			if (P % i == 0)
			{
				prime = false;
				break;
			}
		if (!prime && solve(P, A) == A) cout << "yes\n";
		else cout << "no\n";
	}
}

// https://www.acmicpc.net/problem/4233