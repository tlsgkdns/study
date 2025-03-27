#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int N, A[2223][2223], dp[2223][2223];

int solve(int y, int x)
{
	int& ret = dp[y][x];
	if (ret >= 0) return ret;
	if (y == N - 1 && x == N - 1) return ret = 0;
	ret = 1e9 + 7;
	if (y < N - 1) ret = min(ret, solve(y + 1, x) + max(A[y + 1][x] - A[y][x] + 1, 0));
	if (x < N - 1) ret = min(ret, solve(y, x + 1) + max(A[y][x + 1] - A[y][x] + 1, 0));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/11909