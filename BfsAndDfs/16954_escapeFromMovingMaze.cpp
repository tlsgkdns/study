#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

bool maze[8][8][8];
int v[9][8][8];
int dy[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dx[9] = { 0, -1, 1, -1, 1, 0, -1, 0, 1 };

bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < 8 && x < 8);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(maze, false, sizeof(maze));
	memset(v, false, sizeof(v));
	char ch;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			cin >> ch;
			maze[0][i][j] = (ch == '#');
		}
	for (int t = 0; t < 7; t++)
		for (int r = 7; r >= 0; r--)
			for (int c = 0; c < 8; c++)
				if (maze[t][r][c] && r + 1 < 8)
					maze[t + 1][r + 1][c] = true;
	queue<pair<pair<int, int>, int>> q;
	q.push({ {7, 0}, 0 });
	v[0][7][0] = true;
	int ans = 0;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int t = q.front().second;
		q.pop();
		if (y == 0 && x == 7)
		{
			ans = 1;
			break;
		}
		for (int i = 0; i < 9; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nt = (t < 8) ? t + 1 : t;
			if (!inRange(ny, nx) || v[nt][ny][nx]
				|| maze[nt][ny][nx] || maze[t][ny][nx]) continue;
			v[nt][ny][nx] = true;
			q.push({ {ny, nx}, nt });
		}
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/16954