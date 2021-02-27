#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<vector<bool>> ice, visit;
int n, m;
int dfs(int y, int x)
{
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
		if (ice[ny][nx] && !visit[ny][nx])
		{
			visit[ny][nx] = true;
			ret = max(ret, dfs(ny, nx) + 1);
			visit[ny][nx] = false;
		}

	}
	return ret;
}
int main()
{
	cin >> n >> m;
	ice = vector<vector<bool>>(n, vector<bool>(m));
	visit = vector<vector<bool>>(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int ce;
			cin >> ce;
			ice[i][j] = (ce == 1) ? true : false;
		}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ice[i][j])
			{
				visit[i][j] = true;
				ans = max(ans, dfs(i, j));
				visit = vector<vector<bool>>(n, vector<bool>(m, false));
			}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5578

/*
Tried to dynamic programming but failed.
So, I coded simply, expecting got result "Times out"
But, Unexpectedly, I got "Correct"
*/