#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
ll dp[51][101][101];
ll C[51], S[51];
int N, D;
ll solve(int idx, int remain, int curCnt)
{
	if (idx == N) return 0;
	ll& ret = dp[idx][remain][curCnt];
	if (ret >= 0) return ret;
	if (curCnt < C[idx])
		for (int i = idx + 1; i < min(remain + idx + 1, N); i++)
			ret = max(ret, solve(idx, remain - (i - idx), curCnt + 1) + S[i]);
	ret = max(ret, solve(idx + 1, remain, 0) + (C[idx] - curCnt) * S[idx]);
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> C[i];
	for (int i = 0; i < N; i++) cin >> S[i];
	cin >> D;
	cout << solve(0, D, 0) << '\n';
}

// https://www.acmicpc.net/problem/1423