#include <iostream>
#include <cstring>
using namespace std;

char board[51][51];
int v[51][51];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int N, M;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
bool dfs(int y, int x)
{
	bool ret = false;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!inRange(ny, nx) || board[ny][nx] != board[y][x]) continue;
		if (v[ny][nx] < 0)
		{
			v[ny][nx] = v[y][x] + 1;
			ret |= dfs(ny, nx);
		}
		else if (v[ny][nx] >= v[y][x] + 3)
			return true;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	bool ans = false;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (v[i][j] == -1)
			{
				v[i][j] = 0;
				ans |= dfs(i, j);
			}
	if (ans) cout << "Yes\n"; else cout << "No\n";
}

// https://www.acmicpc.net/problem/16929