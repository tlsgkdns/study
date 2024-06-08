#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, ans = 0, K, S[21], B[21], dp[21][2];

int solve(int idx, bool b)
{
	if (idx == N - 1) return 0;
	int& ret = dp[idx][b];
	if (ret >= 0) return ret;
	ret = 1000000007;
	if (idx + 1 <= N - 1)ret = min(ret, solve(idx + 1, b) + S[idx]);
	if (idx + 2 <= N - 1)ret = min(ret, solve(idx + 2, b) + B[idx]);
	if (!b && idx + 3 <= N - 1) ret = min(ret, solve(idx + 3, true) + K);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N - 1; i++) cin >> S[i] >> B[i];
	cin >> K;
	cout << solve(0, false) << '\n';
}

// https://www.acmicpc.net/problem/21317