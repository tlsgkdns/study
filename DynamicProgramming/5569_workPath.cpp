#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 100000;
int W, H, dp[101][101][3][2];

int solve(int w, int h, int d, bool t)
{
	if (w == W && h == H) return 1;
	int& ret = dp[w][h][d][t];
	if (ret >= 0) return ret;
	ret = 0;
	if (w < W)
	{
		if (d == 2 || d == 1) ret += solve(w + 1, h, true, false);
		else if (!t) ret += solve(w + 1, h, true, true);
		ret %= MOD;
	}
	if (h < H)
	{
		if (d == 2 || d == 0) ret += solve(w, h + 1, false, false);
		else if (!t) ret += solve(w, h + 1, false, true);
		ret %= MOD;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> W >> H;
	memset(dp, -1, sizeof(dp));
	cout << solve(1, 1, 2, false) << '\n';
}

// https://www.acmicpc.net/problem/5569