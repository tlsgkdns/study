#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
int arr[100], N;
ll dp[101][21];
ll solve(int idx, int p)
{
	if (p < 0 || p > 20) return 0;
	if (idx == N - 1) return (arr[idx] == p);
	ll& ret = dp[idx][p];
	if (ret >= 0) return ret;
	return ret = solve(idx + 1, p + arr[idx]) + solve(idx + 1, p - arr[idx]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cout << solve(1, arr[0]) << '\n';
}

// https://www.acmicpc.net/problem/5557