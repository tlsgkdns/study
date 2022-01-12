#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int dy[10] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
int dx[10] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };
char board[101][101];
string mv;
int R, C, Jy, Jx;
vector<pair<int, int>> pos;

int getDist(int y1, int x1, int y2, int x2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}
bool robots(int cmd)
{
	int nJy = Jy + dy[cmd];
	int nJx = Jx + dx[cmd];
	vector<pair<int, int>> tmp;
	for (int i = 0; i < pos.size(); i++)
	{
		int dist = 100001;
		pair<int, int> ps;
		for (int d = 1; d < 10; d++)
		{
			int ny = pos[i].first + dy[d];
			int nx = pos[i].second + dx[d];
			if (dist > getDist(nJy, nJx, ny, nx))
			{
				ps = { ny, nx };
				dist = getDist(nJy, nJx, ny, nx);
			}
		}
		tmp.push_back(ps);
	}
	memset(board, '.', sizeof(board));
	board[nJy][nJx] = 'I';
	Jy = nJy; Jx = nJx;
	vector<pair<int, int>> bomb;
	for (int i = 0; i < tmp.size(); i++)
	{
		int y = tmp[i].first;
		int x = tmp[i].second;
		if (board[y][x] == 'I') return false;
		if (board[y][x] == 'R')
		{
			board[y][x] = 'B';
			bomb.push_back({ y, x });
		}
		if (board[y][x] == '.')
			board[y][x] = 'R';
	}

	for (int i = 0; i < bomb.size(); i++)
		board[bomb[i].first][bomb[i].second] = '.';
	pos = vector<pair<int, int>>();
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			if (board[r][c] == 'R')
				pos.push_back({ r, c });
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'I')
			{
				Jy = i; Jx = j;
			}
			if (board[i][j] == 'R')
				pos.push_back({ i, j });
		}
	cin >> mv;
	int ans = -1;
	for (int i = 0; i < (int)mv.size(); i++)
	{
		if (!robots(mv[i] - '0'))
		{
			ans = i + 1;
			break;
		}
	}
	if (ans == -1)
		for (int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
				cout << board[r][c];
			cout << '\n';
		}
	else
		cout << "kraj " << ans << '\n';
}

// https://www.acmicpc.net/problem/8972