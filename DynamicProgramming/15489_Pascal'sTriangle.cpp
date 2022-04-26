#include <iostream>

using namespace std;

int R, C, W;
int dp[31][31];

int main()
{
	cin >> R >> C >> W;
	dp[0][0] = 1;
	for (int i = 1; i <= 30; i++)
		for (int j = 0; j <= i; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	int ans = 0;
	R--; C--;
	for (int i = R; i < R + W; i++)
		for (int j = C; j <= C + (i - R); j++)
			ans += dp[i][j];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15489