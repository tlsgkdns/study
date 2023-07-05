#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N, dp[1001];
int A[1001], ans = 0;
int solve(int idx)
{
	int& ret = dp[idx];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = idx + 1; i < N; i++)
		if (A[idx] > A[i])
			ret = max(solve(i) + 1, ret);
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
		ans = max(solve(i) + 1, ans);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11722