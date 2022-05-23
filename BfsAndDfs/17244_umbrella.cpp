#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

pii src, dst;
int N, M, house[51][51], S, v[51][51][129], ans, ob = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
char ch;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			switch (ch)
			{
			case '#':
				S = -1;
				break;
			case '.':
				S = 0;
				break;
			case 'S':
				src = { i, j };
				S = 0;
				break;
			case 'X':
				ob++;
				S = ob;
				break;
			default:
				dst = { i, j };
				S = 0;
			}
			house[i][j] = S;
		}
	queue<pair<pair<int, int>, int>> q;
	q.push({ src, 0 });
	v[src.first][src.second][0] = 0;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int c = q.front().second;
		q.pop();
		if (make_pair(y, x) == dst && c == ((1 << ob) - 1))
		{
			ans = v[y][x][(1 << ob) - 1];
			break;
		}
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || house[ny][nx] < 0) continue;
			int nc = c;
			if (house[ny][nx] > 0)	nc |= (1 << (house[ny][nx] - 1));
			if (v[ny][nx][nc] != -1) continue;
			v[ny][nx][nc] = v[y][x][c] + 1;
			q.push({ {ny, nx}, nc });
		}
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/17244