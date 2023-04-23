#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
int R, C, ans1 = 0, ans2 = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
char M[251][251];
bool v[251][251];
bool inRange(int y, int x)
{
	return y >= 0 && y < R&& x < C&& x >= 0;
}
pii dfs(int y, int x)
{
	pii ret = { (M[y][x] == 'v'), (M[y][x] == 'k') };
	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!inRange(ny, nx) || M[ny][nx] == '#' || v[ny][nx]) continue;
		v[ny][nx] = true;
		pii npos = dfs(ny, nx);
		ret.first += npos.first; ret.second += npos.second;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			cin >> M[r][c];
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
		{
			if (v[r][c] || M[r][c] == '#') continue;
			v[r][c] = true;
			pii ret = dfs(r, c);
			if (ret.first < ret.second) ans1 += ret.second;
			else ans2 += ret.first;
		}
	cout << ans1 << " " << ans2 << '\n';
}

// https://www.acmicpc.net/problem/3187