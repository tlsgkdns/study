#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<vector<int>> board;
vector<vector<int>> piece;
vector<int> pos;
vector<pair<int, int>> info; // f : 움직임, s : 위치
int ptoi(int a, int b) { return n * a + b; }

bool movePiece(int ps, int npos, int num, bool rev)
{
	int idx = 0;
	piece;
	vector<int> frnt, bck;
	for (; num != piece[ps][idx]; idx++) frnt.push_back(piece[ps][idx]);
	for (; idx < piece[ps].size(); idx++) bck.push_back(piece[ps][idx]);
	piece[ps] = frnt;
	if (rev) reverse(bck.begin(), bck.end());
	for (int b : bck) { info[b].second = npos; piece[npos].push_back(b); }
	if (piece[npos].size() > 3) return true;
	return false;
}
bool block(int num, int y, int x)
{
	int opp, m = info[num].first;
	switch (m)
	{
	case 0:
		opp = 1;
		break;
	case 1:
		opp = 0;
		break;
	case 2:
		opp = 3;
		break;
	default:
		opp = 2;
	}
	int ny = y + dy[opp];
	int nx = x + dx[opp];
	info[num].first = opp;
	if (ny < 0 || nx < 0 || ny == n || nx == n || board[ny][nx] == 2) return (piece[num].size() > 3);
	return movePiece(ptoi(y, x), ptoi(ny, nx), num, (board[ny][nx] == 1));
}


int main()
{
	int ans = -1, turn = 0;
	cin >> n >> k;
	board.resize(n, vector<int>(n));
	piece.resize(n * n, vector<int>());
	info.resize(k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> y >> x >> info[i].first;
		int p = ptoi(y - 1, x - 1);
		piece[p].push_back(i);
		info[i].second = p;
		info[i].first--;
	}

	while (true)
	{
		bool fl = false;
		if (turn > 1000) break;
		turn++;
		for (int i = 0; i < k; i++)
		{
			int ps = info[i].second, idx = 0;
			int y = ps / n; int x = ps % n;
			int ny = y + dy[info[i].first];
			int nx = x + dx[info[i].first];
			if (ny < 0 || nx < 0 || ny == n || nx == n || board[ny][nx] == 2)
			{
				if (block(i, y, x)) { fl = true; break; }
				continue;
			}
			int nps = ptoi(ny, nx);
			if (movePiece(ps, nps, i, (board[ny][nx] == 1))) { fl = true; break; }
		}
		piece;
		if (fl) { ans = turn; break; }
	}
	cout << ans << endl;
}

// https://www.acmicpc.net/problem/17837