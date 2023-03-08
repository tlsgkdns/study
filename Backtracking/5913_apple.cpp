#include <iostream>

using namespace std;

bool v[6][6];
int Y, X, K, C = 25, ans = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y > 0 && x > 0 && y <= 5 && x <= 5;
}
void dfs(int ay, int ax, int by, int bx, int cnt)
{
	if (ay == by && ax == bx)
	{
		ans += (cnt == 0);
		return;
	}
	for (int d = 0; d < 4; d++)
	{
		int ny1 = ay + dy[d];
		int nx1 = ax + dx[d];
		if (!inRange(ny1, nx1) || v[ny1][nx1]) continue;
		for (int i = 0; i < 4; i++)
		{
			int ny2 = by + dy[i];
			int nx2 = bx + dx[i];
			if (!inRange(ny2, nx2) || v[ny2][nx2]) continue;
			v[ny1][nx1] = true;
			v[ny2][nx2] = true;
			dfs(ny1, nx1, ny2, nx2, (cnt - 2 + (ny1 == ny2 && nx1 == nx2)));
			v[ny1][nx1] = false;
			v[ny2][nx2] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K;
	C -= K;
	while (K--)
	{
		cin >> Y >> X;
		v[Y][X] = true;
	}
	v[1][1] = true; v[5][5] = true;
	dfs(1, 1, 5, 5, C - 2);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5913