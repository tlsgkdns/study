#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
bool maze[11][11];
int v[11][11][11][11];
int N, M, ans = 0;
char ch;
pii blue, red, dst;

int dy[4] = { -1, 1, 0 ,0 };
int dx[4] = { 0, 0, -1, 1 };

pii moveMarble(int y, int x, int oy, int ox, int dir)
{
	if (make_pair(y, x) == dst) return dst;
	while (make_pair(y, x) != dst)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if ((make_pair(oy, ox) != dst && make_pair(oy, ox) == make_pair(ny, nx)) || !maze[ny][nx]) break;
		y = ny; x = nx;
	}
	return { y, x };
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	memset(maze, true, sizeof(maze));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch == 'R') red = { i, j };
			if (ch == 'B') blue = { i, j };
			if (ch == 'O') dst = { i, j };
			if (ch == '#') maze[i][j] = false;
		}
	queue<pair<pii, pii>> q;
	q.push({ red, blue });
	v[red.first][red.second][blue.first][blue.second] = 0;
	while (!q.empty())
	{
		pii R = q.front().first;
		pii B = q.front().second;
		q.pop();
		if (v[R.first][R.second][B.first][B.second] > 10) continue;
		if (R == dst)
		{
			ans = 1;
			break;
		}
		for (int d = 0; d < 4; d++)
		{
			pii nr = moveMarble(R.first, R.second, B.first, B.second, d);
			pii nb = moveMarble(B.first, B.second, nr.first, nr.second, d);
			nr = moveMarble(nr.first, nr.second, nb.first, nb.second, d);
			nb = moveMarble(nb.first, nb.second, nr.first, nr.second, d);
			if (nb == dst || v[nr.first][nr.second][nb.first][nb.second] >= 0) continue;
			v[nr.first][nr.second][nb.first][nb.second] = v[R.first][R.second][B.first][B.second] + 1;
			q.push({ nr, nb });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13459