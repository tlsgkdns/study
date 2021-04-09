#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> maze;
vector<vector<bool>> v[2];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	int n, m, sx, sy, ex, ey, ans = -1;
	cin >> n >> m;
	cin >> sx >> sy;
	cin >> ex >> ey;
	maze.resize(n, vector<int>(m));
	v[0].resize(n, vector<bool>(m, false));
	v[1].resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> maze[i][j];

	queue<pair<pair<int, int>, pair<int, bool>>> q;
	q.push(make_pair(make_pair(sx - 1, sy - 1), make_pair(0, false)));
	v[0][sx - 1][sy - 1] = true;

	while (!q.empty())
	{
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int depth = q.front().second.first;
		bool used = q.front().second.second;

		if (curX == ex - 1 && curY == ey - 1) { ans = depth; break; }
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextY < 0 || nextX < 0 || nextX >= n || nextY >= m || v[used][nextX][nextY]) continue;
			if (maze[nextX][nextY] == 0)
			{
				v[used][nextX][nextY] = true;
				q.push(make_pair(make_pair(nextX, nextY), make_pair(depth + 1, used)));
			}

			if (maze[nextX][nextY] == 1 && !used)
			{
				v[true][nextX][nextY] = true;
				q.push(make_pair(make_pair(nextX, nextY), make_pair(depth + 1, true)));
			}

		}
	}

	cout << ans << endl;
	return 0;
}
// https://www.acmicpc.net/problem/14923
/*
bfs + more space for prev state.
*/