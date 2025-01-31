#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

queue<pair<int, int>> q;
int N, M, v[3001][3001], sy, sx, G[3001][3001];
bool f = true;
char ch;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
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
			cin >> ch;
			if (ch == '2')
			{
				sy = i;
				sx = j;
			}
			G[i][j] = (ch - '0');
		}
	q.push({ sy, sx });
	v[sy][sx] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (G[y][x] >= 3)
		{
			cout << "TAK\n" << v[y][x] << '\n';
			f = false;
			break;
		}
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || v[ny][nx] >= 0 || G[ny][nx] == 1) continue;
			v[ny][nx] = v[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	if (f) cout << "NIE\n";
}

// https://www.acmicpc.net/problem/17129