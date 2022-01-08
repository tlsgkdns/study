#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
ll dp[31][31][31];
char grid[30][30];
ll M, N;
ll solve(int y, int x, int c)
{
	if (y == M) return 1;
	ll& ret = dp[y][x][c];
	if (ret != -1) return ret;
	int ny = (x == N - 1) ? y + 1 : y;
	int nx = (x == N - 1) ? 0 : x + 1;
	if (grid[y][x] == 'B')
	{
		if (x >= c) return ret = 0;
		return ret = solve(ny, nx, c);
	}
	if (grid[y][x] == 'R') return ret = solve(ny, nx, min(c, x));
	if (x >= c) return ret = solve(ny, nx, c);
	return ret = solve(ny, nx, min(c, x)) + solve(ny, nx, c);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> grid[i][j];
	cout << solve(0, 0, N) << '\n';
}
// https://www.acmicpc.net/problem/15113