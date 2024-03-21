#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000007;
int N, M, C, dp[51][51][51][51], P[51][51], X, Y;

int solve(int y, int x, int prv, int cnt)
{
	if (cnt < 0) return 0;
	int& ret = dp[y][x][prv][cnt];
	if (y == N && x == M)
	{
		return ret = (cnt == 0);
	}
	if (ret >= 0) return ret;
	ret = 0;
	if (y < N)
	{
		if (P[y + 1][x] == 0) ret += solve(y + 1, x, prv, cnt) % MOD;
		if (P[y + 1][x] > prv && cnt > 0) ret += solve(y + 1, x, P[y + 1][x], cnt - 1) % MOD;
	}
	if (x < M)
	{
		if (P[y][x + 1] == 0) ret += solve(y, x + 1, prv, cnt) % MOD;
		if (P[y][x + 1] > prv && cnt > 0) ret += solve(y, x + 1, P[y][x + 1], cnt - 1) % MOD;
	}
	ret %= MOD;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> C;
	for (int i = 1; i <= C; i++)
	{
		cin >> X >> Y;
		P[X][Y] = i;
	}
	for (int i = 0; i <= C; i++)
		cout << solve(1, 1, P[1][1], i - (P[1][1] > 0)) << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/1513