#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int N, M, cnt = 1;
int board[51][51], v[51][51][4][5], ans = -1;
char ch;
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
pii start;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	memset(board, 0, sizeof(board));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch == '#') board[i][j] = -1;
			if (ch == 'S') start = { i, j };
			if (ch == 'C')
			{
				board[i][j] = cnt;
				cnt++;
			}
		}

	queue<pair<pii, pii>> q;
	q.push({ start, {0, 0} });
	v[start.first][start.second][0][0] = 0;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int gift = q.front().second.first;
		int prev = q.front().second.second;
		q.pop();
		if (gift == 3)
		{
			ans = v[y][x][gift][prev];
			break;
		}
		for (int d = 1; d <= 4; d++)
		{
			if (d == prev) continue;
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || board[ny][nx] < 0) continue;
			if (board[ny][nx] > 0 && gift == board[ny][nx]) continue;
			int ng = board[ny][nx] + gift;
			if (v[ny][nx][ng][d] != -1) continue;
			v[ny][nx][ng][d] = v[y][x][gift][prev] + 1;
			q.push({ {ny, nx}, {ng, d} });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1175