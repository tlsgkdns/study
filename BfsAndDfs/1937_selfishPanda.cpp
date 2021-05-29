#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans = -1;
vector<vector<int>> bamboo, dp;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int dfs(int y, int x)
{
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny == n
			|| nx == n || bamboo[ny][nx] <= bamboo[y][x]) continue;
		ret = max(ret, dfs(ny, nx) + 1);
	}
	return ret;
}
int main()
{
	cin >> n;
	bamboo.resize(n, vector<int>(n));
	dp.resize(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> bamboo[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans = max(dfs(i, j), ans);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1937