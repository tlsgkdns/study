#include <iostream>
#include <vector>
using namespace std;

int board[5][5];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };
vector<bool> v(1000001, false);
int dfs(int s, int y, int x, int d)
{
	if (d == 6)
	{
		if (v[s]) return 0;
		v[s] = true;
		return 1;
	}
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
		ret += dfs(10 * s + board[ny][nx], ny, nx, d + 1);
	}
	return ret;
}
int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];
	int ans = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			ans += dfs(0, i, j, 0);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/2210