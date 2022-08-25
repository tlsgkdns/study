#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, v[101][101], ans1 = 0, ans2 = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < N;
}
void dfs(vector<vector<char>>& grid, int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!inRange(ny, nx) || v[ny][nx] || grid[y][x] != grid[ny][nx]) continue;
		v[ny][nx] = true;
		dfs(grid, ny, nx);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<vector<char>> g1(N, vector<char>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> g1[i][j];
	vector<vector<char>> g2(g1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (g2[i][j] == 'G')
				g2[i][j] = 'R';
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!v[i][j])
			{
				v[i][j] = true;
				ans1++;
				dfs(g1, i, j);
			}
	memset(v, false, sizeof(v));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!v[i][j])
			{
				v[i][j] = true;
				ans2++;
				dfs(g2, i, j);
			}
	cout << ans1 << " " << ans2 << '\n';
}

// https://www.acmicpc.net/problem/10026