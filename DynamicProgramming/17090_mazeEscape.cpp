#include <iostream>
#include <cstring>
using namespace std;

char maze[501][501];
int N, M, dp[501][501], ans = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool v[501][501];

bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < N && x < M);
}
int solve(int y, int x)
{
	if (!inRange(y, x)) return 1;
	if (dp[y][x] >= 0) return dp[y][x];
	if (v[y][x]) return 0;
	v[y][x] = true;
	switch (maze[y][x])
	{
	case 'D':
		dp[y][x] = solve(y + 1, x);
		break;
	case 'U':
		dp[y][x] = solve(y - 1, x);
		break;
	case 'L':
		dp[y][x] = solve(y, x - 1);
		break;
	case 'R':
		dp[y][x] = solve(y, x + 1);
		break;
	}
	return dp[y][x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> maze[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			ans += solve(i, j);
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17090