#include <iostream>

using namespace std;

int N, M, ans[2];
char ch;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool v[101][101], W[101][101];
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N&& x < M;
}
int dfs(int y, int x)
{
	int ret = 1;
	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!inRange(ny, nx) || v[ny][nx] || W[y][x] != W[ny][nx]) continue;
		v[ny][nx] = true;
		ret += dfs(ny, nx);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			W[i][j] = (ch == 'B');
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (v[i][j]) continue;
			v[i][j] = true;
			int a = dfs(i, j);
			ans[W[i][j]] += a * a;
		}
	cout << ans[0] << " " << ans[1] << '\n';
}

// https://www.acmicpc.net/problem/1303