#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, ans = 0;
int A[1001], dp[1001];

int solve(int idx)
{
	if (idx >= N) return 0;
	int& ret = dp[idx];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = idx + 1; i < N; i++)
		if (A[idx] < A[i])
			ret = max(ret, solve(i) + A[i]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N; A[0] = 0;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) ans = max(solve(i) + A[i], ans);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11055