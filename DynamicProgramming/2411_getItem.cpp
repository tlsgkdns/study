#include <iostream>
#include <cstring>
using namespace std;
int dp[101][101], map[101][101], ys[101], xs[101];
int N, M, A, B, Y, X;
int solve(int y, int x, int item)
{
	if (y > N || x > M) return 0;
	if (map[y][x] == -1) return 0;
	if (ys[y] < (A - item - (map[y][x] == 1))
		|| xs[x] < (A - item - (map[y][x] == 1)))
		return 0;
	if (y == N && x == M)
		return 1;
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	return ret = solve(y + 1, x, item + (map[y][x] == 1))
		+ solve(y, x + 1, item + (map[y][x] == 1));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	memset(map, 0, sizeof(map));
	cin >> N >> M >> A >> B;
	for (int i = 0; i < A; i++)
	{
		cin >> Y >> X;
		map[Y][X] = 1;
		while (Y > 0)
		{
			ys[Y]++;
			Y--;
		}
		while (X > 0)
		{
			xs[X]++;
			X--;
		}
	}
	for (int i = 0; i < B; i++)
	{
		cin >> Y >> X;
		map[Y][X] = -1;
	}
	cout << solve(1, 1, (map[1][1] == 1));
}

// https://www.acmicpc.net/problem/2411