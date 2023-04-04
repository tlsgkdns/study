#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
char ch;
bool G[1001][1001];
int N, M, K, Y1, X1, Y2, X2, v[1001][1001], ans = -1;
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, 1, -1 };
queue<pair<int, int>> q;

bool inRange(int y, int x)
{
	return y > 0 && x > 0 && y <= N && x <= M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> ch;
			if (ch == '.') G[i][j] = false;
			else G[i][j] = true;
		}
	cin >> Y1 >> X1 >> Y2 >> X2;
	q.push({ Y1, X1 });
	memset(v, -1, sizeof(v));
	v[Y1][X1] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == Y2 && x == X2)
		{
			ans = v[y][x];
			break;
		}
		for (int d = 1; d <= 4; d++)
		{
			for (int c = 1; c <= K; c++)
			{
				int ny = y + dy[d] * c;
				int nx = x + dx[d] * c;
				if (!inRange(ny, nx) || (v[ny][nx] >= 0 && v[ny][nx] == v[y][x]) || G[ny][nx]) break;
				if (v[ny][nx] >= 0) continue;
				v[ny][nx] = v[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16930