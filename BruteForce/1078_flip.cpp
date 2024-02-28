#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
ll D, ans = -1;
vector<ll> T, E;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> D;
	if (D % 9 > 0)
	{
		cout << -1 << '\n';
		return 0;
	}
	D /= 9;
	T.push_back(1); E.push_back(0);
	for (int i = 0; i < 13; i++)
	{
		T.push_back(T.back() * 10);
		E.push_back(E.back() * 10 + 1);
	}

	for (int l = 2; l < 13; l++)
	{
		ll x = 0;
		ll tmp = D;
		for (int i = 0; 2 * i < l - 1; i++)
		{
			int b = tmp % 10;
			ll m = E[l - 1 - i * 2] * b;
			tmp -= m;
			tmp /= 10;
			if (i == 0 && b == 0)
			{
				x += T[l - 1] + 1;
			}
			else if (m > 0)
				x += T[l - 1 - i] * abs(b);
			else
				x += T[i] * abs(b);
		}
		if (tmp == 0)
		{
			ans = x;
			break;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1078