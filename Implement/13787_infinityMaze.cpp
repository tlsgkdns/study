#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<pair<int, int>, char>> ans;
char maze[101][101];
int dp[101][101][4];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool inRange(int y, int x, int H, int W)
{
	return (y >= 0 && x >= 0 && y < H && x < W);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int H, W, dir = 0;
	long long L;
	int y = 0, x = 0;
	while (true)
	{
		memset(dp, -1, sizeof(dp));
		memset(maze, '.', sizeof(maze));
		vector<pair<pair<int, int>, int>> route;
		cin >> H >> W >> L;
		if (H == 0 && W == 0 && L == 0) break;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				cin >> maze[i][j];
				if (maze[i][j] == 'N')
				{
					dir = 0;
					y = i; x = j;
				}
				if (maze[i][j] == 'E')
				{
					dir = 1;
					y = i; x = j;
				}
				if (maze[i][j] == 'S')
				{
					dir = 2;
					y = i; x = j;
				}
				if (maze[i][j] == 'W')
				{
					dir = 3;
					y = i; x = j;
				}
			}
		dp[y][x][dir] = 0;
		int loopStart = -1, period = 0;
		while (true)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			int nd = dir;
			while (!inRange(ny, nx, H, W) || maze[ny][nx] == '#')
			{
				nd = (nd + 1) % 4;
				if (dp[y][x][nd] != -1)
				{
					loopStart = dp[y][x][nd];
					period = dp[y][x][dir] - dp[y][x][nd];
					break;
				}
				dp[y][x][nd] = dp[y][x][dir];
				ny = y + dy[nd]; nx = x + dx[nd];
			}
			if (loopStart != -1) break;
			if (dp[ny][nx][nd] != -1)
			{
				route.push_back({ {ny, nx}, dir });
				loopStart = dp[ny][nx][nd] + 1;
				period = dp[y][x][dir] - dp[ny][nx][nd] + 1;
				break;
			}
			route.push_back({ {ny, nx}, nd });
			dp[ny][nx][nd] = dp[y][x][dir] + 1;
			y = ny; x = nx; dir = nd;
		}
		int step = (loopStart >= L) ? L - 1 : ((L - loopStart - 1) % (period)) + loopStart;
		char f;
		y = route[step].first.first;
		x = route[step].first.second;
		dir = route[step].second;
		if (dir == 0) f = 'N'; if (dir == 1) f = 'E';
		if (dir == 2) f = 'S'; if (dir == 3) f = 'W';
		ans.push_back({ {y + 1, x + 1}, f });
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first.first << " "
			<< ans[i].first.second << " "
			<< ans[i].second << '\n';
	}
}

// https://www.acmicpc.net/problem/13787