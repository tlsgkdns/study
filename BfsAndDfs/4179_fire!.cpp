#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool isExit(int r, int c, int w, int h)
{
	return ((r == 0) || (c == 0) || (r == h - 1) || (c == w - 1));
}
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
	queue<pair<int, int>> fire, escape;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 'J')
			{
				v[i][j] = 0;
				escape.push(make_pair(i, j));
			}
			if (b[i][j] == 'F')
			{
				f[i][j] = 0;
				fire.push(make_pair(i, j));
			}
		}
	while (!fire.empty())
	{
		int y = fire.front().first;
		int x = fire.front().second;
		fire.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!isInside(ny, nx, h, w) || f[ny][nx] != -1 || b[ny][nx] == '#') continue;
			f[ny][nx] = f[y][x] + 1;
			fire.push(make_pair(ny, nx));
		}
	}
	while (!escape.empty())
	{
		int y = escape.front().first;
		int x = escape.front().second;
		escape.pop();
		if (isExit(y, x, w, h))
		{
			a = v[y][x];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!isInside(ny, nx, h, w) || v[ny][nx] != -1
				|| b[ny][nx] == '#' || (f[ny][nx] != -1 && f[ny][nx] <= v[y][x] + 1)) continue;
			v[ny][nx] = v[y][x] + 1;
			escape.push(make_pair(ny, nx));
		}
	}
	if (a != -1) a++;
	ans.push_back(a);
	for (int a : ans)
		if (a == -1) cout << "IMPOSSIBLE" << '\n';
		else cout << a << '\n';
}

// https://www.acmicpc.net/problem/4179