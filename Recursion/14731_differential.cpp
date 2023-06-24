#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
ll N, C, K, ans;
ll calc(ll num)
{
	if (num <= 15)
	{
		return pow(2, num);
	}
	ll h = num / 2;
	ll s = calc(h);
	s *= s;
	if (num % 2) return (s * 2) % MOD;
	else return s % MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> C >> K;
		if (K == 0) continue;
		ans += (calc(K - 1) * ((K * C) % MOD)) % MOD;
		ans %= MOD;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14731