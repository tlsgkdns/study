#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
char maze[101][101];
int v[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int N, M;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < M && x < N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> maze[i][j];
	deque<pair<int, int>> dq;
	dq.push_back({ 0, 0 });
	v[0][0] = 0;
	while (!dq.empty())
	{
		int y = dq.front().first;
		int x = dq.front().second;
		dq.pop_front();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || v[ny][nx] != -1) continue;
			v[ny][nx] = true;
			if (maze[ny][nx] == '0')
			{
				v[ny][nx] = v[y][x];
				dq.push_front({ ny, nx });
			}
			else
			{
				v[ny][nx] = v[y][x] + 1;
				dq.push_back({ ny, nx });
			}
		}
	}
	cout << v[M - 1][N - 1] << '\n';
}

// https://www.acmicpc.net/problem/1261