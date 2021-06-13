#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> grid, ans;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int r, c, n;
void bomb()
{
	queue<pair<int, int>> q;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (grid[i][j] == 'O')
				q.push(make_pair(i, j));
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		ans[y][x] = '.';
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny == r || nx == c) continue;
			ans[ny][nx] = '.';
		}
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			grid[i][j] = ans[i][j];

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> n;
	grid.resize(r, vector<char>(c));
	ans.resize(r, vector<char>(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			cin >> grid[i][j];
			ans[i][j] = grid[i][j];
		}

	for (int t = 2; t <= n; t++)
	{
		if (t % 2 == 0)
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					ans[i][j] = 'O';
		else
			bomb();
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << ans[i][j];
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/16918