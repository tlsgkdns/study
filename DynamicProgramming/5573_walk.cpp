#include <iostream>
using namespace std;

int H, W, N, G[1002][1002], dp[1002][1002];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> H >> W >> N;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			cin >> G[i][j];
	dp[1][1] = N - 1;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
		{
			int d = dp[i][j];
			dp[i][j + 1] += (d / 2) + (G[i][j] == 1 && (d % 2 > 0));
			dp[i + 1][j] += (d / 2) + (G[i][j] == 0 && (d % 2 > 0));
		}
	int y = 1, x = 1;
	while (y <= H && x <= W)
	{
		int d = G[y][x];
		if (dp[y][x] % 2 > 0) d = !d;
		if (d) x++;
		else y++;
	}
	cout << y << " " << x << '\n';
}

// https://www.acmicpc.net/problem/5573