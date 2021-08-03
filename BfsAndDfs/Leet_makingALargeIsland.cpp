#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, is, cnt = 1, ans = -1;
vector<vector<bool>> grid;
vector<vector<int>> group;
vector<int> areas;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int di[8] = { 2, -2, 0, 0, 1, -1, -1, 1 };
int dj[8] = { 0, 0, -2, 2, -1, 1, -1, 1 };
int dfs(int y, int x, int num)
{
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n
			|| group[ny][nx] != -1 || grid[ny][nx] == 0) continue;
		group[ny][nx] = num;
		ret += dfs(ny, nx, num) + 1;
	}
	return ret;
}

int main()
{
	cin >> n;
	grid.resize(n, vector<bool>(n));
	group.resize(n, vector<int>(n, -1));
	areas.push_back(0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> is;
			grid[i][j] = is;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 0 || group[i][j] != -1) continue;
			group[i][j] = cnt;
			int area = dfs(i, j, cnt) + 1;
			areas.push_back(area);
			cnt++;
		}
	ans = (areas.size() <= 1) ? 1 : areas[1] + 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 1) continue;
			int a = 1;
			vector<bool> v(areas.size() + 1, false);
			for (int d = 0; d < 4; d++)
			{
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n
					|| grid[ny][nx] == 0 || v[group[ny][nx]]) continue;
				v[group[ny][nx]] = true;
				a += areas[group[ny][nx]];
			}
			ans = max(ans, a);
		}
	if (ans > n* n) ans = n * n;
	cout << ans << '\n';
}

// https://leetcode.com/problems/making-a-large-island/