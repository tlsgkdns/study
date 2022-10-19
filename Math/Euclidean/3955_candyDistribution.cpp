#include <iostream>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll MAX = 1000000000;
ll K, C, T;
int gcd(int a, int b)
{
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

pii solve(int a, int b)
{
	if (b > 0)
	{
		pii tmp = solve(b, a % b);
		return { tmp.second, tmp.first - (a / b) * tmp.second };
	}
	return { 1, 0 };
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> K >> C;
		ll ans = 0;
		if (gcd(K, C) != 1)
			ans = -1;
		else
		{
			ans = (solve(C, K).first + K) % K;
			while (C * ans <= K) ans += K;
			if (ans > MAX) ans = -1;
		}
		if (ans < 0) cout << "IMPOSSIBLE\n";
		else cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/3955