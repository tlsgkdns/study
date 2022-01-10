#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

bool space[50][50];
int v[50][50];
int N, M;
int dy[8] = { -1, 1, -1, 0, 1, 0, -1, 1 };
int dx[8] = { 0, 0, 1, 1, 1, -1, -1, -1 };

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
void bfs(int sy, int sx)
{
	int ret = 0;
	v[sy][sx] = 0;
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || v[ny][nx] <= v[y][x] + 1) continue;
			v[ny][nx] = v[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> space[i][j];
			v[i][j] = 2501;
		}
	int ans = -1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (!space[i][j]) continue;
			bfs(i, j);
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ans = max(v[i][j], ans);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17086