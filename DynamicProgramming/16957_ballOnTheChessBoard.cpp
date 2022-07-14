#include <iostream>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;
int R, C;
const pii dum = { -1, -1 };
int chess[501][501], ans[501][501];
pii dp[501][501];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { 0, -1, 1, -1, 1, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < R && x < C;
}
pii solve(int y, int x)
{
	pii& ret = dp[y][x];
	if (ret != dum) return ret;
	ret = { y, x };
	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!inRange(ny, nx)) continue;
		if (chess[ret.first][ret.second] > chess[ny][nx])
			ret = { ny, nx };
	}
	ret = solve(ret.first, ret.second);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 501; i++)
		for (int j = 0; j < 501; j++)
			dp[i][j] = dum;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> chess[i][j];
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			pii now = solve(i, j);
			ans[now.first][now.second]++;
		}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/16957