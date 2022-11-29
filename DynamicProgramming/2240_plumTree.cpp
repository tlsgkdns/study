#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, W, dp[1001][31][2], F[1001];

int solve(int t, int mv, bool pos)
{
	if (t == T) return 0;
	int& ret = dp[t][mv][pos];
	if (ret >= 0) return ret;
	int g = (F[t] == pos);
	if (mv > 0) ret = solve(t + 1, mv - 1, !pos) + g;
	ret = max(ret, solve(t + 1, mv, pos) + g);
	return ret;
}
int main()
{
	cin >> T >> W;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < T; i++)
	{
		cin >> F[i];
		--F[i];
	}
	cout << max(solve(0, W, false), solve(0, W - 1, 1)) << '\n';
}

// https://www.acmicpc.net/problem/2240