#include <iostream>
#include <cstring>

int N, M, W[301][301], dp[301][301];
using namespace std;

int solve(int y, int x)
{
	if (y == N - 1 && x == M - 1) return 0;
	int& ret = dp[y][x];
	if (ret >= 0) return ret;
	ret = 0;
	if (y < N - 1) ret = max(ret, solve(y + 1, x) + W[y + 1][x]);
	if (x < M - 1) ret = max(ret, solve(y, x + 1) + W[y][x + 1]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> W[i][j];
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) + W[0][0] << '\n';
}

// https://www.acmicpc.net/problem/14430