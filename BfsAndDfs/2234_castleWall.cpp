#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, cnt = 0, area1 = -1, area2 = -1;
vector<vector<int>> castle, group;
vector<vector<int>> adj;
vector<int> areas;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

int dfs(int y, int x, int g)
{
	int ret = 0;
	for (int i = 0; i <= 3; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if (group[ny][nx] != -1)
		{
			if (group[ny][nx] != g)
			{
				adj[g].push_back(group[ny][nx]);
				adj[group[ny][nx]].push_back(g);
			}
			continue;
		}
		if (castle[y][x] & (1 << i)) continue;
		group[ny][nx] = g;
		ret += dfs(ny, nx, g) + 1;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	castle.resize(m, vector<int>(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> castle[i][j];
	adj.resize(n * m + 1); group.resize(m, vector<int>(n, -1));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (group[i][j] != -1) continue;
			group[i][j] = cnt;
			int a = dfs(i, j, cnt) + 1;
			area1 = max(a, area1);
			areas.push_back(a);
			cnt++;
		}
	for (int i = 0; i < adj.size(); i++)
		for (int j = 0; j < adj[i].size(); j++)
			area2 = max(area2, (areas[i] + areas[adj[i][j]]));
	cout << cnt << '\n' << area1 << '\n' << area2 << '\n';
}

// https://www.acmicpc.net/problem/2234