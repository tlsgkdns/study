#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;
const ll INF = 1000000000000000007;
ll dp[102][102][2], P[102], T, N, A, D[102];

ll solve(int l, int r, bool p)
{
	if (l == 0 && r == N) return 0;
	ll& ret = dp[l][r][p];
	if (ret >= 0) return ret;
	ret = INF; ll s = (N - (r - l));
	if (l > 0)
		ret = min(ret, solve(l - 1, r, true) + s * ((p) ? (D[l]) : P[r - 1] - P[l - 1]));
	if (r < N)
		ret = min(ret, solve(l, r + 1, false) + s * ((p) ? (P[r] - P[l]) : D[r]));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> A;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i < N; i++)
		{
			cin >> D[i];
			P[i] = D[i] + P[i - 1];
		}
		ll ans = INF;
		if (A > 1) ans = min(ans, solve(A - 2, A, true) + (N - 1) * D[A - 1]);
		if (A < N) ans = min(ans, solve(A - 1, A + 1, false) + (N - 1) * D[A]);
		if (ans == INF) ans = 0;
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/4243