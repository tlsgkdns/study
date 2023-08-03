#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
int N, G[33][33];
ll dp[33][33][3];
ll solve(int y, int x, int s)
{
	if (y == N - 1 && x == N - 1) return 1;
	ll& ret = dp[y][x][s];
	if (ret >= 0) return ret;
	ret = 0;
	if (s != 0 && y < N - 1 && !G[y + 1][x]) ret += solve(y + 1, x, 1);
	if (s != 1 && x < N - 1 && !G[y][x + 1]) ret += solve(y, x + 1, 0);
	if (y < N - 1 && x < N - 1 && !G[y + 1][x] && !G[y][x + 1] && !G[y + 1][x + 1])
		ret += solve(y + 1, x + 1, 2);
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
			cin >> G[i][j];
	cout << solve(0, 1, 0) << '\n';
}

// https://www.acmicpc.net/problem/17069