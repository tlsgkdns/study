#include <iostream>
#include <cstring>

using namespace std;
int dp[102][2][102], T, N, K;

int solve(int idx, int p, int cnt)
{
	int& ret = dp[idx][p][cnt];
	if (ret >= 0) return ret;
	if (idx == N) return ret = (cnt == 0);
	if (p == 0) ret = solve(idx + 1, 1, cnt) + solve(idx + 1, 0, cnt);
	else ret = solve(idx + 1, 0, cnt) + ((cnt > 0) ? solve(idx + 1, 1, cnt - 1) : 0);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		memset(dp, -1, sizeof(dp));
		cout << solve(0, 0, K) << '\n';
	}
}

// https://www.acmicpc.net/problem/2698