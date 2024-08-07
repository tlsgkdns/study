#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
ll dp[1516][16], N, T[1516], F[1516], t = 1, f = 5;

ll solve(int d, int n)
{
	if (d == N) return (n == 0);
	ll& ret = dp[d][n];
	if (ret >= 0) return ret;
	ret = solve(d + 1, (n + T[d]) % 15) + solve(d + 1, (n + F[d]) % 15);
	ret %= MOD;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		T[i] = t % 15;
		F[i] = f % 15;
		t *= 10; t %= 15;
		f *= 10; f %= 15;
	}
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/20500