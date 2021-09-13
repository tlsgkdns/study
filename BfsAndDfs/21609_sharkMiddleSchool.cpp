#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int rainbowBlk = 0, blackBlk = -1, emptyBlk = -2;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int N, M, score = 0;
vector<vector<int>> grid;

void applyGrav()
{
	grid;
	vector<int> bottom(N, N);
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] == emptyBlk) continue;
			if (grid[i][j] != blackBlk)
				swap(grid[bottom[j]-- - 1][j], grid[i][j]);
			else
				bottom[j] = i;
		}
	}
}
void rotateGrid()
{
	vector<vector<int>> tmp(N, vector<int>(N));
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			tmp[(N - 1) - x][y] = grid[y][x];
	grid = tmp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	grid.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> grid[i][j];
	while (true)
	{
		vector<vector<bool>> v(N, vector<bool>(N, false));
		vector<pair<int, int>> blocks;
		int rainbow = 0;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
			{
				if (v[r][c] || grid[r][c] <= 0) continue;
				vector<pair<int, int>> blks;
				int clr = grid[r][c]; int rb = 0;
				blks.push_back({ r, c });
				queue<pair<int, int>> q;
				q.push({ r, c }); v[r][c] = true;
				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++)
					{
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (ny < 0 || nx < 0 || ny >= N || nx >= N || v[ny][nx]) continue;
						if (grid[ny][nx] == rainbowBlk) rb++;
						else if (grid[ny][nx] != clr) continue;
						v[ny][nx] = true;
						q.push({ ny, nx }); blks.push_back({ ny, nx });
					}
				}
				if (blocks.size() < blks.size())
				{
					blocks = blks;
					rainbow = rb;
				}
				else if (blocks.size() == blks.size() && rainbow < rb)
				{
					blocks = blks;
					rainbow = rb;
				}
				else if (blocks.size() == blks.size() && rb == rainbow)
				{
					blocks = blks;
					rainbow = rb;
				}
				for (int y = 0; y < N; y++)
					for (int x = 0; x < N; x++)
						if (grid[y][x] == rainbowBlk)
							v[y][x] = false;
			}
		if (blocks.size() < 2) break;
		int sc = blocks.size();
		score += sc * sc;
		for (auto b : blocks)
			grid[b.first][b.second] = emptyBlk;
		applyGrav();
		rotateGrid();
		applyGrav();
	}
	cout << score << '\n';
}

// https://www.acmicpc.net/problem/21609