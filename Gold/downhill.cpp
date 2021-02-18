#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> map, c;

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, -1, 0, 1 };

int m, n;
int dfs(int y, int x)
{
	if (x == n - 1 && y == m - 1) return 1;
	int& ret = c[y][x];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextX = dx[i] + x;
		int nextY = dy[i] + y;
		if (nextX >= n || nextY >= m || nextX < 0 || nextY < 0)
			continue;
		if (map[y][x] > map[nextY][nextX])
			ret += dfs(nextY, nextX);
	}

	return ret;
}
int main()
{
	cin >> m >> n;
	map.resize(m, vector<int>(n));
	c.resize(m, vector<int>(n, -1));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	int ans = dfs(0, 0);
	cout << ans << '\n';
	return 0;
}

// https://www.acmicpc.net/problem/1520

/*
dfs + dynamic programming
I little surprised its difficulty(Gold 4) is harder than I thought
*/