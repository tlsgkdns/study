#include <iostream>
#include <cstring>

using namespace std;

int N, M, G[2][31][31], P[31][31];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool ans = false, v[31][31];
void solve(int y, int x, int n, int c)
{
	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || v[ny][nx] || G[0][ny][nx] != c) continue;
		v[ny][nx] = true;
		G[0][ny][nx] = n;
		solve(ny, nx, n, c);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, false, sizeof(v));
	cin >> N >> M;
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> G[k][i][j];
	bool f = true;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			P[i][j] = G[0][i][j];
			if (G[0][i][j] != G[1][i][j]) f = false;
		}
	ans = f;
	for (int y = 0; y < N && !ans; y++)
		for (int x = 0; x < M && !ans; x++)
			if (!v[y][x] && G[0][y][x] != G[1][y][x])
			{
				v[y][x] = true;
				int tmp = G[0][y][x];
				G[0][y][x] = G[1][y][x];
				solve(y, x, G[1][y][x], tmp);
				bool f = true;
				for (int i = 0; i < N && f; i++)
					for (int j = 0; j < M && f; j++)
						if (G[0][i][j] != G[1][i][j])
						{
							f = false;
							break;
						}
				ans = f;
				for (int i = 0; i < N; i++)
					for (int j = 0; j < M; j++)
						G[0][i][j] = P[i][j];
			}
	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

// https://www.acmicpc.net/problem/22352