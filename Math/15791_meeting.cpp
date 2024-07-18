#include <iostream>

using namespace std;
using ll = long long;
const ll MOD = 1000000007;
ll N, M, L = 1, R = 1;

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
	cin >> N >> M;
	for (int i = 2; i <= N; i++)
		L = (L * i) % MOD;
	for (int i = 2; i <= M; i++)
		R = (R * i) % MOD;
	for (int i = 2; i <= N - M; i++)
		R = (R * i) % MOD;
	cout << L * pow(R, MOD - 2) % MOD << '\n';
}

// https://www.acmicpc.net/problem/15791