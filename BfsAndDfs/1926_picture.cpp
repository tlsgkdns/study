#include <iostream>
#include <algorithm>
int N, M, S = 0, C = 0;
using namespace std;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool v[501][501], P[501][501];
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
		if (!inRange(ny, nx) || !P[ny][nx] || v[ny][nx]) continue;
		v[ny][nx] = true;
		ret += dfs(ny, nx);
	}
	return ret;
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> P[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (P[i][j] && !v[i][j])
			{
				C++;
				v[i][j] = true;
				S = max(S, dfs(i, j));
			}
	cout << C << '\n' << S << '\n';
}

// https://www.acmicpc.net/problem/1926