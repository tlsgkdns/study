#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, T, K[101], S[101], dp[101][10001];

int solve(int idx, int t)
{
	if (idx == N) return 0;
	int& ret = dp[idx][t];
	if (ret >= 0) return ret;
	ret = max(ret, solve(idx + 1, t));
	if (K[idx] <= t) ret = max(ret, solve(idx + 1, t - K[idx]) + S[idx]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> T;
	for (int i = 0; i < N; i++) cin >> K[i] >> S[i];
	cout << solve(0, T) << '\n';
}

// https://www.acmicpc.net/problem/14728