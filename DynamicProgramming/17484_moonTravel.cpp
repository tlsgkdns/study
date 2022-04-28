#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int dx[4] = { 0, -1, 0, 1 };
int dp[7][7][4], space[7][7];
int N, M;

int solve(int y, int x, int pre)
{
	if (y == N) return 0;
	int& ret = dp[y][x][pre];
	if (ret != INF) return ret;
	for (int i = 1; i <= 3; i++)
	{
		if (pre == i) continue;
		int nx = dx[i] + x;
		if (nx < 0 || nx >= M) continue;
		ret = min(ret, solve(y + 1, nx, i) + space[y + 1][nx]);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> space[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < 4; k++)
				dp[i][j][k] = INF;
	int ans = INF;
	for (int i = 0; i < M; i++)
		ans = min(ans, space[0][i] + solve(0, i, 0));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17484