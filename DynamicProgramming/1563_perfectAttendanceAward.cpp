#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 1000000;
int N, X, A, dp[1001][2][3];

int solve(int idx, int l, int a)
{
	if (idx == N) return 1;
	int& ret = dp[idx][l][a];
	if (ret >= 0) return ret;
	ret = solve(idx + 1, l, 0);
	if (l < 1) ret += solve(idx + 1, l + 1, 0);
	ret %= MOD;
	if (a < 2) ret += solve(idx + 1, l, a + 1);
	ret %= MOD;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << solve(0, 0, 0) << '\n';
}

// https://www.acmicpc.net/problem/1563