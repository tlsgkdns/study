#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>> board;
vector<vector<int>> adj;
vector<vector<pair<int, int>>> mileStone;
int R, C, N, col = 1;
bool canMoveLeft(int y, int x)
{
	if (board[y + 1][x - 1] != '.' || board[y][x - 1] != '.') return false;
	return true;
}
bool canMoveRight(int y, int x)
{
	if (board[y + 1][x + 1] != '.' || board[y][x + 1] != '.') return false;
	return true;
}
void moveStone(int r, int c)
{
	auto idx = upper_bound(adj[c].begin(), adj[c].end(), r);
	int h = *idx - 1;
	if (board[h + 1][c] == 'X')
	{
		adj[c].insert(idx, h);
		board[h][c] = 'O';
	}
	else
	{
		if (canMoveLeft(h, c))
		{
			mileStone[col].push_back({ h, c });
			moveStone(h, c - 1);

		}
		else if (canMoveRight(h, c))
		{
			mileStone[col].push_back({ h, c });
			moveStone(h, c + 1);
		}
		else
		{
			adj[c].insert(idx, h);
			board[h][c] = 'O';
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	board.resize(R + 2, vector<char>(C + 2, 'X'));
	adj.resize(C + 2);
	for (int j = 1; j <= C; j++)
		adj[j].push_back(0);
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'X') adj[j].push_back(i);
		}
	for (int j = 1; j <= C; j++)
		adj[j].push_back(R + 1);
	mileStone.resize(C + 2);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> col;
		if (mileStone[col].empty())
			moveStone(1, col);
		else
		{
			while (!mileStone[col].empty() && board[mileStone[col].back().first][mileStone[col].back().second] != '.')
				mileStone[col].pop_back();
			if (mileStone[col].empty()) moveStone(1, col);
			else moveStone(mileStone[col].back().first, mileStone[col].back().second);
		}
	}
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			cout << board[i][j];
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/3025