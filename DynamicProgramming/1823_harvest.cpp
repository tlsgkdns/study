#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[2001][2001], N, C[2001];
int solve(int l, int r)
{
	if (l > r) return 0;
	int& ret = dp[l][r];
	if (ret >= 0) return ret;
	int s = N - (r - l);
	ret = max(solve(l + 1, r) + (C[l] * s), solve(l, r - 1) + (C[r] * s));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> C[i];
	cout << solve(0, N - 1) << '\n';
}

// https://www.acmicpc.net/problem/1823