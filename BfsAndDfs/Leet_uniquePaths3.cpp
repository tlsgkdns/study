#include <vector>

using namespace std;

class Solution {
public:
	pair<int, int> s, e;
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	int path = 0, n, m;
	vector<vector<bool>> v;
	int dfs(vector<vector<int>>& grid, int y, int x, int visit)
	{
		if (y == e.first && x == e.second)
		{
			if (visit == path) return 1;
			else return 0;
		}
		int ret = 0;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny == n || nx == m
				|| v[ny][nx] || grid[ny][nx] == -1) continue;
			v[ny][nx] = true;
			ret += dfs(grid, ny, nx, visit + 1);
			v[ny][nx] = false;
		}
		return ret;
	}
	int uniquePathsIII(vector<vector<int>>& grid) {
		n = grid.size(); m = grid[0].size();
		v.resize(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == -1) continue;
				if (grid[i][j] == 1) s = make_pair(i, j);
				if (grid[i][j] == 2) e = make_pair(i, j);
				path++;
			}
		v[s.first][s.second] = true;
		return dfs(grid, s.first, s.second, 1);
	}
};

// https://leetcode.com/problems/unique-paths-iii/