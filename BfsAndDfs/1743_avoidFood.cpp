#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K, R, C;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool F[102][102], v[102][102];
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
int solve(int y, int x)
{
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!inRange(ny, nx) || v[ny][nx] || !F[ny][nx]) continue;
		v[ny][nx] = true;
		ret += solve(ny, nx);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> R >> C;
		F[R - 1][C - 1] = true;
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (F[i][j] && !v[i][j])
			{
				v[i][j] = true;
				ans = max(ans, solve(i, j));
			}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1743