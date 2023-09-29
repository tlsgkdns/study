#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1000000007;
int dp[5001][5001], A[5001], N;

int solve(int l, int r)
{
	if (l >= r) return 0;
	int& ret = dp[l][r];
	if (ret >= 0) return ret;
	ret = INF;
	if (A[l] == A[r]) ret = min(ret, solve(l + 1, r - 1));
	ret = min(ret, solve(l + 1, r) + 1);
	ret = min(ret, solve(l, r - 1) + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cout << solve(0, N - 1) << '\n';
}

// https://www.acmicpc.net/problem/1695