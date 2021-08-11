#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2501;
int N, M;
char c;
vector<vector<int>> board;
vector<vector<int>> dp;
vector<vector<bool>> v;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

int dfs(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= M || board[y][x] == -1) return 0;
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	if (v[y][x]) return INF;
	v[y][x] = true;
	int a = -1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + (dy[i] * board[y][x]);
		int nx = x + (dx[i] * board[y][x]);
		a = max(a, dfs(ny, nx) + 1);
	}
	ret = a;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	board.resize(N, vector<int>(M));
	dp.resize(N, vector<int>(M, -1));
	v.resize(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			board[i][j] = (c == 'H') ? -1 : c - '0';
		}
	int ans = dfs(0, 0);
	ans = (ans >= INF) ? -1 : ans;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1103