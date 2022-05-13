#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N, M, T, ans = -1;
int v[101][101][2], m[101][101];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	queue<pair<pair<int, int>, bool>> q;
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> m[i][j];
	q.push({ {0, 0}, false });
	v[0][0][0] = 0;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		bool s = q.front().second;
		q.pop();
		if (y == N - 1 && x == M - 1)
		{
			ans = v[y][x][s];
			break;
		}
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			bool ns = (s || (m[ny][nx] == 2));
			if (v[ny][nx][ns] != -1) continue;
			if (!ns && m[ny][nx] == 1) continue;
			v[ny][nx][ns] = v[y][x][s] + 1;
			q.push({ {ny, nx}, ns });
		}
	}
	if (ans > T || ans < 0) cout << "Fail\n";
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17836