#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N, dp[3001], P[3001], T, H, S[3001];
int solve(int idx)
{
	if (idx > N) return 0;
	int& ret = dp[idx];
	if (ret >= 0) return ret;
	ret = 1000000007;
	ret = min(ret, solve(idx + 1) + P[idx] * T);
	for (int i = idx; i <= N; i++)
	{
		int m = (idx + i) / 2;
		int l = ((m - idx + 1) * P[m]) - (S[m] - S[idx - 1]);
		int r = (S[i] - S[m]) - (P[m] * (i - m));
		ret = min(ret, solve(i + 1) + H + ((l + r) * T));
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> P[i];
	sort(P + 1, P + N + 1);
	for (int i = 1; i <= N; i++)
		S[i] = S[i - 1] + P[i];
	cin >> T >> H;
	cout << solve(1) << '\n';
}

// https://www.acmicpc.net/problem/1866