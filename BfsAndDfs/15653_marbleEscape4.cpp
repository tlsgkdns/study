#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

bool board[10][10];
int v[10][10][10][10];
int N, M, ans = -1;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
char ch;
pii blue, red, dst;

pii moveMarble(pii p, pii opp, int dir)
{
	while (p != dst)
	{
		pii np = { p.first + dy[dir] , p.second + dx[dir] };
		if (!board[np.first][np.second] || (opp != dst && opp == np)) break;
		p = np;
	}
	return p;
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
			if (ch == 'R') red = { i, j };
			if (ch == 'B') blue = { i, j };
			if (ch == 'O') dst = { i, j };
			board[i][j] = (ch != '#');
		}
	queue<pair<pii, pii>> q;
	q.push({ red, blue });
	v[red.first][red.second][blue.first][blue.second] = 0;
	pii np;
	while (!q.empty() && ans < 0)
	{
		pii rpos = q.front().first;
		pii bpos = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			pii trp = moveMarble(rpos, bpos, d);
			pii tbp = moveMarble(bpos, trp, d);
			pii nrp = moveMarble(trp, tbp, d);
			pii nbp = moveMarble(tbp, nrp, d);
			if (nbp == dst || v[nrp.first][nrp.second][nbp.first][nbp.second] >= 0) continue;
			v[nrp.first][nrp.second][nbp.first][nbp.second] = v[rpos.first][rpos.second][bpos.first][bpos.second] + 1;
			if (nrp == dst)
			{
				ans = v[nrp.first][nrp.second][nbp.first][nbp.second];
				break;
			}
			q.push({ nrp, nbp });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15653