#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> area;
int n, s = 0, mn = numeric_limits<int>::max(), mx = -1, ans = 1;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void dfs(vector<vector<bool>>& v, int y, int x, const int l)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n
			|| v[ny][nx] || area[ny][nx] <= l) continue;
		v[ny][nx] = true;
		dfs(v, ny, nx, l);
	}
}
int main()
{
	cin >> n; area.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> area[i][j];
			mx = max(area[i][j], mx);
			mn = min(area[i][j], mn);
		}

	for (int level = mn; level < mx; level++)
	{
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && area[i][j] > level)
				{
					visited[i][j] = true;
					dfs(visited, i, j, level);
					s++;
				}
			}
		ans = max(s, ans); s = 0;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2468