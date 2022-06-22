#include <iostream>
#include <algorithm>
using namespace std;
const int INF = -1000000000;
int N, M, K, ans = 0;
int board[10][10];
bool v[10][10];
int solve(int y, int x, int d)
{
	if (d == K) return 0;
	if (y == N) return INF;
	if (x == M) return solve(y + 1, 0, d);
	if ((y > 0 && v[y - 1][x]) || (x > 0 && v[y][x - 1])) return solve(y, x + 1, d);
	int ret = solve(y, x + 1, d);
	v[y][x] = true;
	ret = max(solve(y, x + 1, d + 1) + board[y][x], ret);
	v[y][x] = false;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	cout << solve(0, 0, 0) << '\n';
}

// https://www.acmicpc.net/problem/18290