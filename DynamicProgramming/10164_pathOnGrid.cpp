#include <iostream>
#include <cstring>
using namespace std;

int N, M, K;
int dp[16][16][2];
int solve(int y, int x, bool ok)
{
	if (y > N || x > M) return 0;
	if (y == N && x == M) return (ok == 1);
	int& ret = dp[y][x][ok];
	if (ret != -1) return ret;
	int num = (y - 1) * M + x;
	ret = solve(y + 1, x, (K == num) || ok) + solve(y, x + 1, (K == num) || ok);
	return ret;
}
int main()
{
	cin >> N >> M >> K;
	memset(dp, -1, sizeof(dp));
	int ans = (K == 0) ? solve(1, 1, true) : solve(1, 1, false);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10164