#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N, C[1001], dp[1001][1001];

int solve(int l, int r, bool t)
{
	if (l > r) return 0;
	int& ret = dp[l][r];
	if (ret >= 0) return ret;
	if (t) ret = max(solve(l + 1, r, !t) + C[l], solve(l, r - 1, !t) + C[r]);
	else ret = min(solve(l + 1, r, !t), solve(l, r - 1, !t));
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < N; i++) cin >> C[i];
		cout << solve(0, N - 1, true) << '\n';
	}
}

// https://www.acmicpc.net/problem/11062