#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
ll ans, A[2001], dp[2001][2001];
int N;
ll solve(int l, int r)
{
	if (l == r) return 0;
	ll& ret = dp[l][r];
	if (ret >= 0) return ret;
	if (A[l] < A[r])
	{
		r = (r < N - 1) ? r + 1 : 0;
		if (l == r) return ret = A[l];
	}
	else
	{
		l = (l > 0) ? l - 1 : N - 1;
		if (l == r) return ret = A[l];
	}
	ret = max(ret, solve(((l > 0) ? l - 1 : N - 1), r) + A[l]);
	ret = max(ret, solve(l, ((r < N - 1) ? r + 1 : 0)) + A[r]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++)
	{
		int l = (i > 0) ? i - 1 : N - 1, r = (i < N - 1) ? i + 1 : 0;
		ll a = solve(l, r) + A[i];
		ans = max(ans, a);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10714