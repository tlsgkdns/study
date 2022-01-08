#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> ans;
pair<int, int> far;
int T, R, C, a = -1;
char maze[1001][1001];
bool v[1001][1001];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < R && x < C;
}

void dfs(int y, int x, int cost)
{
	if (a < cost)
	{
		a = cost;
		far = { y, x };
	}
	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!inRange(ny, nx) || maze[ny][nx] == '#' || v[ny][nx]) continue;
		v[ny][nx] = true;
		dfs(ny, nx, cost + 1);
		v[ny][nx] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> C >> R;
		pair<int, int> spos;
		a = 0;
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
			{
				cin >> maze[r][c];
				if (maze[r][c] == '.') spos = { r, c };
			}
		memset(v, false, sizeof(v));
		v[spos.first][spos.second] = true;
		dfs(spos.first, spos.second, 0);
		memset(v, false, sizeof(v));
		v[far.first][far.second] = true;
		dfs(far.first, far.second, 0);
		ans.push_back(a);
	}
	for (int i = 0; i < T; i++)
		cout << "Maximum rope length is " << ans[i] << ".\n";
}

// https://www.acmicpc.net/problem/3482