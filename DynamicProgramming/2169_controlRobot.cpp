#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = -1000000000;
int N, M;
int vals[1001][1001], dp[1001][1001][3]; // 0 : 양쪽, 1 : 왼쪽, 2 : 오른쪽

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
int solve(int y, int x, int dir)
{
	if (!inRange(y, x)) return INF;
	if (y == N - 1 && x == M - 1) return vals[y][x];
	int& ret = dp[y][x][dir];
	if (ret != -1) return ret;
	if (dir == 0)
		return ret = max(solve(y, x - 1, 1), max(solve(y, x + 1, 2), solve(y + 1, x, 0))) + vals[y][x];
	else if (dir == 1)
		return ret = max(solve(y, x - 1, 1), solve(y + 1, x, 0)) + vals[y][x];
	else
		return ret = max(solve(y, x + 1, 2), solve(y + 1, x, 0)) + vals[y][x];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> vals[i][j];
	cout << solve(0, 0, 2) << '\n';
}

// https://www.acmicpc.net/problem/2169