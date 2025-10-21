#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N, M, A[301][301], dp[301][301];

int solve(int y, int x)
{
	if (y == N - 1 && x == M - 1) return 0;
	int& ret = dp[y][x];
	if (ret >= 0) return ret;
	ret = 1e9;
	for (int c = 1; y + c < N && c <= A[y][x]; c++)
		ret = min(ret, solve(y + c, x) + 1);
	for (int c = 1; x + c < M && c <= A[y][x]; c++)
		ret = min(ret, solve(y, x + c) + 1);
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/17391