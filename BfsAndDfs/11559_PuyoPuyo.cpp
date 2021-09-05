#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int R = 12;
const int C = 6;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<vector<char>> field(R, vector<char>(C, 'N'));

bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < R && x < C);
}
int dfs1(vector<vector<bool>>& v, int y, int x)
{
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!inRange(ny, nx) || field[y][x] != field[ny][nx] || v[ny][nx]) continue;
		v[ny][nx] = true;
		ret += dfs1(v, ny, nx);
	}
	return ret;
}
void dfs2(vector<vector<bool>>& v, int y, int x, char puyo)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!inRange(ny, nx) || puyo != field[ny][nx] || v[ny][nx]) continue;
		v[ny][nx] = true;
		field[ny][nx] = '.';
		dfs2(v, ny, nx, puyo);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> field[i][j];
	int ans = 0;

	while (true)
	{
		vector<vector<bool>> v1(13, vector<bool>(6, false)), v2(13, vector<bool>(6, false));
		vector<int> t(6, R);
		bool bomb = false;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
			{
				if (field[i][j] == '.' || v1[i][j]) continue;
				v1[i][j] = true;
				if (dfs1(v1, i, j) >= 4)
				{
					bomb = true;
					v2[i][j] = true;
					dfs2(v2, i, j, field[i][j]);
					field[i][j] = '.';
				}
			}
		for (int r = R - 1; r >= 0; r--)
			for (int c = 0; c < C; c++)
			{
				if (field[r][c] == '.') continue;
				if (t[c] - 1 != r)
				{
					field[t[c] - 1][c] = field[r][c];
					field[r][c] = '.';
				}
				t[c]--;
			}
		if (bomb) ans++;
		else break;
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/11559