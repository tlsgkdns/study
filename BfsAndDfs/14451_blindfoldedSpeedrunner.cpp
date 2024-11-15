#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int N, v[21][21][4][21][21][4], ans = 0;
char ch;
bool H[21][21];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
queue<pair<pair<pair<int, int>, int>, pair<pair<int, int>, int>>> q;
bool inRange(int r, int c)
{
	return r >= 0 && c >= 0 && r < N && c < N;
}
bool dst(int r, int c)
{
	return r == 0 && c == N - 1;
}
void chk(int& r, int& c, int pr, int pc)
{
	if (!inRange(r, c) || H[r][c] || dst(pr, pc))
	{
		r = pr;
		c = pc;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			H[i][j] = (ch == 'H');
		}
	q.push({ { {N - 1, 0}, 0 }, { {N - 1, 0}, 1} });
	v[N - 1][0][0][N - 1][0][1] = 0;
	while (!q.empty())
	{
		int r1 = q.front().first.first.first;
		int c1 = q.front().first.first.second;
		int d1 = q.front().first.second;
		int r2 = q.front().second.first.first;
		int c2 = q.front().second.first.second;
		int d2 = q.front().second.second;
		q.pop();
		if (dst(r1, c1) && dst(r2, c2))
		{
			ans = v[r1][c1][d1][r2][c2][d2];
			break;
		}
		int nd1 = (d1 + 1) % 4;
		int nd2 = (d2 + 1) % 4;
		if (v[r1][c1][nd1][r2][c2][nd2] < 0)
		{
			v[r1][c1][nd1][r2][c2][nd2] = v[r1][c1][d1][r2][c2][d2] + 1;
			q.push({ {{r1, c1}, nd1}, {{r2, c2}, nd2} });
		}
		nd1 = (d1 + 3) % 4;
		nd2 = (d2 + 3) % 4;
		if (v[r1][c1][nd1][r2][c2][nd2] < 0)
		{
			v[r1][c1][nd1][r2][c2][nd2] = v[r1][c1][d1][r2][c2][d2] + 1;
			q.push({ {{r1, c1}, nd1}, {{r2, c2}, nd2} });
		}
		int nr1 = r1 + dy[d1];
		int nc1 = c1 + dx[d1];
		int nr2 = r2 + dy[d2];
		int nc2 = c2 + dx[d2];
		chk(nr1, nc1, r1, c1);
		chk(nr2, nc2, r2, c2);
		if (v[nr1][nc1][d1][nr2][nc2][d2] < 0)
		{
			v[nr1][nc1][d1][nr2][nc2][d2] = v[r1][c1][d1][r2][c2][d2] + 1;
			q.push({ {{nr1, nc1}, d1}, {{nr2, nc2}, d2} });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14451