#include <iostream>
#include <cstring>
using namespace std;

int N, H[21], P[21], dp[21][2002];

int solve(int idx, int h)
{
	if (idx == N) return 0;
	int& ret = dp[idx][h];
	if (ret >= 0) return ret;
	if (h <= H[idx]) return ret = solve(idx + 1, h);
	return ret = max(solve(idx + 1, h), solve(idx + 1, h - H[idx]) + P[idx]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
	for (int i = 0; i < N; i++) cin >> P[i];
	cout << solve(0, 100) << '\n';
}

// https://www.acmicpc.net/problem/1535