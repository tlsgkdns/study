#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1001], N, G[1001];

int solve(int idx)
{
	if (idx == N) return 0;
	int& ret = dp[idx];
	if (ret >= 0) return ret;
	ret = 0;
	int mn = G[idx], mx = G[idx];
	for (int i = idx; i < N; i++)
	{
		mn = min(mn, G[i]); mx = max(mx, G[i]);
		ret = max(ret, solve(i + 1) + mx - mn);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> G[i];
	cout << solve(0) << '\n';
}

// https://www.acmicpc.net/problem/2229