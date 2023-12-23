#include <iostream>

using namespace std;
using ll = long long;
ll S, X, D = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S >> X;
	if (S < X) cout << 0 << '\n';
	else
	{
		int sub = S - X, cnt = 0;
		for (int i = 42; i >= 0; i--)
		{
			if (X & (1LL << i)) ++cnt;
			else if (sub >= (1LL << i) * 2) sub -= (1LL << i) * 2;
		}
		if (sub > 0) cout << 0 << '\n';
		else
		{
			ll ans = (1LL << cnt);
			if (S == X) ans -= 2;
			cout << ans << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/14257