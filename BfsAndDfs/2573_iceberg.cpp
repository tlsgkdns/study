#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, t = 0, ans = 0;
int iceberg[301][301];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<vector<bool>> sea;

void dfs(vector<vector<bool>>& v, int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny == n
			|| nx == m || v[ny][nx] || iceberg[ny][nx] == 0) continue;
		v[ny][nx] = true;
		dfs(v, ny, nx);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL);
	cin >> n >> m; sea.resize(n, vector<bool>(m, true));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> iceberg[i][j];
			if (iceberg[i][j] != 0) sea[i][j] = false;
		}
	while (true)
	{
		vector<vector<bool>> visit(sea);
		bool allSea = true;
		int mass = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mass > 1) break;
				if (!visit[i][j])
				{
					allSea = false;
					visit[i][j] = true;
					dfs(visit, i, j);
					mass++;
				}
			}
			if (mass > 1) break;
		}
		if (allSea)
		{
			ans = 0;
			break;
		}
		if (mass > 1)
		{
			ans = t;
			break;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!sea[i][j])
				{
					int side = 0;
					for (int d = 0; d < 4; d++)
					{
						int ni = i + dy[d];
						int nj = j + dx[d];
						if (sea[ni][nj]) side++;
					}
					iceberg[i][j] = max(0, iceberg[i][j] - side);
				}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (iceberg[i][j] == 0)
					sea[i][j] = true;
		t++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2573