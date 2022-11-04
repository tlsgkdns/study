#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int N, M, T[1001][1001], v[1001][1001];
pair<int, int> S;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N&& x < M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> T[i][j];
			if (T[i][j] == 2) S = { i, j };
			if (T[i][j] != 1) v[i][j] = 0;
		}
	queue<pair<int, int>> q;
	q.push(S);
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || v[ny][nx] >= 0 || T[ny][nx] == 0) continue;
			v[ny][nx] = v[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << v[i][j] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/14940