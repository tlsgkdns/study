#include <iostream>

using namespace std;
using ll = long long;
const ll MOD = 1000000007;
ll N, M, K, F[4000001];

ll pow(ll n, ll cnt)
{
	if (cnt == 0) return 1;
	if (cnt % 2 > 0) return (pow(n, cnt - 1) * n) % MOD;
	ll h = pow(n, cnt / 2);
	return h * h % MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M;
	F[0] = F[1] = 1;
	for (int i = 2; i <= 4000000; i++) F[i] = F[i - 1] * i % MOD;
	while (M--)
	{
		cin >> N >> K;
		cout << F[N] * pow((F[K] * F[N - K]) % MOD, MOD - 2) % MOD << '\n';
	}
}

// https://www.acmicpc.net/problem/13977