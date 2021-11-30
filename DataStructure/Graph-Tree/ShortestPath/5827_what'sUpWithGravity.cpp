#include <iostream>
#include <vector>
#include <deque>

using namespace std;
using pos = pair<int, int>;
vector<vector<bool>> grid;
vector<vector<vector<int>>> v;
int N, M;
pos src, dst;
char cell;
int dy[2] = { -1, 1 };

bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < N && x < M);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	grid.resize(N, vector<bool>(M, true)); v.resize(N, vector<vector<int>>(M, vector<int>(2, -1)));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> cell;
			if (cell == '#') grid[i][j] = false;
			if (cell == 'C') src = make_pair(i, j);
			if (cell == 'D') dst = make_pair(i, j);
		}
	deque<pair<pair<int, int>, int>> dq;
	int grv = 1, ans = -1;
	dq.push_back(make_pair(src, grv));
	v[src.first][src.second][grv] = 0;
	while (!dq.empty())
	{
		int y = dq.front().first.first;
		int x = dq.front().first.second;
		int g = dq.front().second;
		dq.pop_front();
		if (dst == make_pair(y, x))
		{
			ans = v[y][x][g];
			break;
		}
		int ny = y + dy[g];
		if (!inRange(ny, x)) continue;
		if (grid[ny][x])
		{
			if (v[ny][x][g] == -1)
			{
				v[ny][x][g] = v[y][x][g];
				dq.push_front({ {ny, x} , g });
			}
		}
		else
		{
			for (int d = -1; d <= 1; d += 2)
			{
				int nx = x + d;
				if (!inRange(y, nx) || !grid[y][nx] || v[y][nx][g] != -1) continue;
				v[y][nx][g] = v[y][x][g];
				dq.push_front({ { y, nx }, g });
			}
			int ng = (g == 0) ? 1 : 0;
			if (v[y][x][ng] == -1)
			{
				v[y][x][ng] = v[y][x][g] + 1;
				dq.push_back({ {y, x}, ng });
			}
		}
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/5827