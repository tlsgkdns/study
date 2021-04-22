#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, ans = -1;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<vector<bool>> maze;

void bfs()
{
	queue<pair<pair<int, int>, int>> q;
	vector<vector<bool>> v(n, vector<bool>(m, false));
	v[0][0] = true;	q.push({ {0, 0}, 1 });
	while (!q.empty())
	{
		pair<pair<int, int>, int> top = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = top.first.first + dy[i];
			int nx = top.first.second + dx[i];
			int cnt = top.second + 1;
			if (ny == n || nx == m || nx < 0 || ny < 0 || !maze[ny][nx] || v[ny][nx]) continue;
			if (ny == n - 1 && nx == m - 1) { ans = cnt; break; }
			v[ny][nx] = true;
			q.push(make_pair(make_pair(ny, nx), cnt));
		}
		if (ans != -1) break;
	}
}
int main()
{
	cin >> n >> m;
	maze.resize(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < m; j++)
			if (line[j] == '1') maze[i][j] = true;
			else maze[i][j] = false;
	}
	bfs();
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2178