#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int R, C;
vector<vector<char>> m;

bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < R && x < C);
}
int bfs(int y, int x)
{
	vector<vector<int>> v(R, vector<int>(C, -1));
	v[y][x] = 0;
	queue<pair<int, int>> q;
	q.push({ y, x });
	int ret = 0;
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (!inRange(nr, nc) || v[nr][nc] != -1 || m[nr][nc] == 'W') continue;
			v[nr][nc] = v[r][c] + 1;
			ret = max(ret, v[nr][nc]);
			q.push({ nr, nc });
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	m.resize(R, vector<char>(C));
	int ans = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> m[i][j];
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (m[i][j] == 'W') continue;
			ans = max(bfs(i, j), ans);
		}
	cout << ans << '\n';
}