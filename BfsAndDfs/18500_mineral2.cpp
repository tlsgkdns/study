#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, N, h, c;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y <= R && x < C);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	bool left = true;
	cin >> R >> C;
	vector<vector<char>> cave(R + 1, vector<char>(C, 'x'));
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> cave[i][j];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> h;
		if (left)
		{
			c = 0;
			while (c < C && cave[R - h][c] == '.') c++;
		}
		else
		{
			c = C - 1;
			while (c >= 0 && cave[R - h][c] == '.') c--;
		}
		left = !left;
		if (c == C || c < 0) continue;
		cave[R - h][c] = '.';
		vector<vector<bool>> v(R + 1, vector<bool>(C, false));
		queue<pair<int, int>> q;
		v[R][0] = true;
		q.push({ R, 0 });
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int d = 0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (!inRange(ny, nx) || cave[ny][nx] != 'x' || v[ny][nx]) continue;
				v[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
		bool br = false;
		while (true)
		{
			vector<vector<char>> tmp = cave;
			for (int r = R - 1; r >= 0; r--)
			{
				if (br) break;
				for (int c = 0; c < C; c++)
				{
					if (v[r][c] || tmp[r][c] == '.') continue;
					if (v[r + 1][c])
					{
						br = true;
						break;
					}
					tmp[r + 1][c] = tmp[r][c];
					tmp[r][c] = '.';
				}
			}
			if (br || (tmp == cave)) break;
			cave = tmp;
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << cave[i][j];
		cout << '\n';
	}
}
// https://www.acmicpc.net/problem/18500