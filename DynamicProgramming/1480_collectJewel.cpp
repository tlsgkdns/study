#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, C, B[14], dp[17000][11][21];

int solve(int sel, int remain, int c)
{
	if (remain == 0) return 0;
	int& ret = dp[sel][remain][c];
	if (ret >= 0) return ret;
	ret = solve(sel, remain - 1, C);
	for (int i = 0; i < N; i++)
	{
		if (sel & (1 << i) || c < B[i]) continue;
		ret = max(solve((sel | (1 << i)), remain, c - B[i]) + 1, ret);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++) cin >> B[i];
	cout << solve(0, M, C) << '\n';
}

// https://www.acmicpc.net/problem/1480