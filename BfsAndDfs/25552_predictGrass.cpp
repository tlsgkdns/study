#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
int N, M, D, cnt = 0, scnt = 0, pcnt = 0, v[1001][1001];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool p[1001][1001], ans = true;
char ch;
queue<pii> q;
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
			if (ch == 'O')
			{
				v[i][j] = 0;
				q.push({ i, j });
				scnt++;
			}
		}
	cin >> D;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch == 'O')
			{
				p[i][j] = true;
				cnt++;
				pcnt += (v[i][j] == 0);
			}
		}
	ans = (scnt == pcnt);
	if (ans)
	{
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int d = 0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				int nxt = (p[ny][nx]) ? 0 : v[y][x] + 1;
				if (!inRange(ny, nx) || (v[ny][nx] != -1 && v[ny][nx] <= nxt)) continue;
				v[ny][nx] = nxt;
				if (v[ny][nx] == D) continue;
				q.push({ ny, nx });
				scnt += p[ny][nx];
			}
		}
	}
	ans = (scnt == cnt);
	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

// https://www.acmicpc.net/problem/25552