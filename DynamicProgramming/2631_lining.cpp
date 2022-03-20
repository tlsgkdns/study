#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[201][201], arr[201];
int N;
int solve(int idx, int prev)
{
	if (idx == N) return 0;
	int& ret = dp[idx][prev];
	if (ret != -1) return ret;
	if (arr[idx] <= prev) return ret = solve(idx + 1, prev);
	return ret = max(solve(idx + 1, prev), solve(idx + 1, arr[idx]) + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int ans = solve(0, 0);
	ans = N - ans;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2631