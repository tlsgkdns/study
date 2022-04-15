#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1001][1001], arr[1001];
int N;

int solve(int idx, int prev)
{
	if (idx == N + 1) return 0;
	int& ret = dp[idx][prev];
	if (ret != -1) return ret;
	if (arr[prev] < arr[idx]) return ret = max(solve(idx + 1, idx) + 1, solve(idx + 1, prev));
	return ret = solve(idx + 1, prev);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	arr[0] = -1;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cout << solve(1, 0) << '\n';
}

// https://www.acmicpc.net/problem/1965