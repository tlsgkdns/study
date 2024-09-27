#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int dp[100001][101], F[100001], N;

int solve(int idx, int p)
{
	if (idx == N) return 0;
	int& ret = dp[idx][p];
	if (ret >= 0) return ret;
	ret = max(ret, solve(idx + 1, p));
	if (p == 0) ret = max(ret, solve(idx + 1, F[idx]));
	else ret = max(ret, solve(idx + 1, F[idx]) + (int)pow(F[idx] - p, 2));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> F[i];
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/25759