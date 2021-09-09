#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
pair<int, int> ex;

bool isInside(int y, int x, int R, int C)
{
	return (y >= 0 && x >= 0 && y < R && x < C);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> ans;
	int w, h, a = -1;
	cin >> h >> w;
	vector<vector<char>> b(h, vector<char>(w));
	vector<vector<int>> f(h, vector<int>(w, -1)), v(h, vector<int>(w, -1));
	queue<pair<int, int>> water, escape;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 'S')
			{
				v[i][j] = 0;
				escape.push(make_pair(i, j));
			}
			if (b[i][j] == '*')
			{
				f[i][j] = 0;
				water.push(make_pair(i, j));
			}
			if (b[i][j] == 'D')
			{
				ex = make_pair(i, j);
			}
		}
	while (!water.empty())
	{
		int y = water.front().first;
		int x = water.front().second;
		water.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!isInside(ny, nx, h, w) || f[ny][nx] != -1 || b[ny][nx] == 'X'
				|| ex == make_pair(ny, nx)) continue;
			f[ny][nx] = f[y][x] + 1;
			water.push(make_pair(ny, nx));
		}
	}
	while (!escape.empty())
	{
		int y = escape.front().first;
		int x = escape.front().second;
		escape.pop();
		if (ex == make_pair(y, x))
		{
			a = v[y][x];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!isInside(ny, nx, h, w) || v[ny][nx] != -1
				|| b[ny][nx] == 'X' || (f[ny][nx] != -1 && f[ny][nx] <= v[y][x] + 1)) continue;
			v[ny][nx] = v[y][x] + 1;
			escape.push(make_pair(ny, nx));
		}
	}
	if (a == -1) cout << "KAKTUS" << '\n';
	else cout << a << '\n';
}
// https://www.acmicpc.net/problem/3055