#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int dp[100][100][81];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
int N, M, K, ans = 0;
string word;
vector<vector<char>> grid;

int solve(int y, int x, int l)
{
	if (l >= word.size()) return 1;
	int& ret = dp[y][x][l];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 1; j <= K; j++)
		{
			int ny = y + dy[i] * j;
			int nx = x + dx[i] * j;
			if (ny < 0 || nx < 0 ||
				ny >= N || nx >= M || grid[ny][nx] != word[l]) continue;
			ret += solve(ny, nx, l + 1);
		}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);  cin.tie(NULL);
	cin >> N >> M >> K;
	memset(dp, -1, sizeof(dp));
	grid.resize(N, vector<char>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> grid[i][j];
	cin >> word;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (grid[i][j] == word[0])
				ans += solve(i, j, 1);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/2186