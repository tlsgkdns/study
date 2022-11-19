#include <iostream>
#include <cstring>

using namespace std;

int dp[3][31], N;
int solve(bool prv, int idx)
{
	if (idx >= N) return (!prv);
	int& ret = dp[prv][idx];
	if (ret >= 0) return ret;
	if (prv == 0)
		return ret = 2 * solve(1, idx + 1) + ((idx < N - 1) ? solve(0, idx + 2) : 0);
	return ret = solve(0, idx + 1) + ((idx < N - 1) ? solve(1, idx + 2) : 0);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << solve(0, 0) << '\n';
}
// https://www.acmicpc.net/problem/2133