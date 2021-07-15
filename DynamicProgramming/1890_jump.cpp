#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<ll>> dp;
vector<vector<int>> board;
int N;

ll solve(int y, int x)
{
	if (y == N - 1 && x == N - 1) return 1;
	if (board[y][x] == 0) return 0;
	if (dp[y][x] != -1) return dp[y][x];
	ll s1 = (y + board[y][x] >= N) ? 0 : solve(y + board[y][x], x);
	ll s2 = (x + board[y][x] >= N) ? 0 : solve(y, x + board[y][x]);
	dp[y][x] = s1 + s2;
	return dp[y][x];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	dp.resize(N, vector<ll>(N, -1));
	board.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	cout << solve(0, 0) << '\n';
}
// https://www.acmicpc.net/problem/1890