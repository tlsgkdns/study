#include <iostream>

using namespace std;
using ll = long long;
ll N, K;
const ll MOD = 1000000007LL;

ll pow(ll a, ll b)
{
	if (b == 0) return 1;
	if (b % 2 == 1) return (pow(a, b - 1) * a) % MOD;
	ll half = pow(a, b / 2) % MOD;
	return (half * half) % MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	ll A = 1, B = 1;
	for (int i = 1; i <= N; i++)
	{
		A *= i;
		A %= MOD;
	}
	for (int i = 1; i <= N - K; i++)
	{
		B *= i;
		B %= MOD;
	}
	for (int i = 1; i <= K; i++)
	{
		B *= i;
		B %= MOD;
	}
	cout << (A * pow(B, MOD - 2)) % MOD << '\n';
}
// https://www.acmicpc.net/problem/11401