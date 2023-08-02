#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int N, M;
bool v[11][11][11][11];
char G[11][11];
pii bpos, rpos, dst;
string ans = "";
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
char P[4] = { 'U', 'D', 'L', 'R' };
bool canMove(int y, int x, int d, int oy, int ox)
{
	if (G[oy][ox] == 'O') return G[y][x] != 'O' && G[y + dy[d]][x + dx[d]] != '#';
	return G[y][x] != 'O' && G[y + dy[d]][x + dx[d]] != '#'
		&& !(y + dy[d] == oy && x + dx[d] == ox);
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == 'R')
			{
				G[i][j] = '.';
				rpos = { i, j };
			}
			if (G[i][j] == 'B')
			{
				G[i][j] = '.';
				bpos = { i, j };
			}
		}
	v[rpos.first][rpos.second][bpos.first][bpos.second] = true;
	queue<pair<pair<pii, pii>, string>> q;
	q.push({ {rpos, bpos}, "" });
	while (!q.empty())
	{
		int ry = q.front().first.first.first;
		int rx = q.front().first.first.second;
		int by = q.front().first.second.first;
		int bx = q.front().first.second.second;
		string r = q.front().second;
		q.pop();
		if (G[by][bx] == 'O') continue;
		if (G[ry][rx] == 'O')
		{
			ans = r;
			break;
		}
		if (r.size() >= 10) continue;
		for (int d = 0; d < 4; d++)
		{
			int nry = ry, nrx = rx, nby = by, nbx = bx;
			while (true)
			{
				if (!canMove(nry, nrx, d, nby, nbx) && !canMove(nby, nbx, d, nry, nrx)) break;
				while (canMove(nry, nrx, d, nby, nbx))
				{
					nry += dy[d];
					nrx += dx[d];
				}
				while (canMove(nby, nbx, d, nry, nrx))
				{
					nby += dy[d];
					nbx += dx[d];
				}
				while (canMove(nry, nrx, d, nby, nbx))
				{
					nry += dy[d];
					nrx += dx[d];
				}
				while (canMove(nby, nbx, d, nry, nrx))
				{
					nby += dy[d];
					nbx += dx[d];
				}
			}
			if (v[nry][nrx][nby][nbx]) continue;
			v[nry][nrx][nby][nbx] = true;
			q.push({ {{nry, nrx}, {nby, nbx}}, r + P[d] });
		}
	}
	if (ans.empty()) cout << -1 << '\n';
	else
	{
		cout << ans.size() << '\n';
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/15644