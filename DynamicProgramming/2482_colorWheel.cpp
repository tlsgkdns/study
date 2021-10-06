#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MOD = 1000000003;
int dp[1001][1001][2][2];
int N, K;
int solve(int idx, int used, bool prevUsed, bool firstUsed)
{
	if (used == K) return 1;
	int& ret = dp[idx][used][prevUsed][firstUsed];
	if (ret != -1) return ret;
	if (N - idx < K - used) return ret = 0;
	if (idx == N - 1)
	{
		if (firstUsed || prevUsed) return ret = 0;
		else return ret = (used == K - 1);
	}
	if (prevUsed) ret = solve(idx + 1, used, false, firstUsed);
	else ret = solve(idx + 1, used + 1, true, firstUsed) % MOD + solve(idx + 1, used, false, firstUsed) % MOD;
	ret %= MOD;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	int ans = solve(1, 0, false, false) % MOD + solve(1, 1, true, true) % MOD;
	ans %= MOD;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/2482