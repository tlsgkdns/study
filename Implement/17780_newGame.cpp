#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };
int tiles[14][14];
int N, K, Y, X, D;
struct token
{
	int dir = 0, num = 0;
	token(int d, int n)
	{
		dir = d;  num = n;
	}
};
vector<vector<vector<token>>> board;

int getOppDir(int dir)
{
	if (dir % 2 == 0) return dir - 1;
	else return dir + 1;
}
bool inRange(int y, int x)
{
	return y >= 1 && x >= 1 && y <= N && x <= N;
}

bool isGameEnd()
{
	board;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (board[i][j].size() >= 4)
				return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> tiles[i][j];
	board.resize(N + 1, vector<vector<token>>(N + 1));
	for (int i = 1; i <= K; i++)
	{
		cin >> Y >> X >> D;
		board[Y][X].push_back(token(D, i));
	}
	int turn = 1;
	for (; turn <= 1000; turn++)
	{
		for (int n = 1; n <= K; n++)
		{
			bool br = false;
			for (int i = 1; i <= N; i++)
			{
				if (br) break;
				for (int j = 1; j <= N; j++)
				{
					if (br) break;
					if (board[i][j].empty() || board[i][j][0].num != n) continue;
					int ny = i + dy[board[i][j][0].dir];
					int nx = j + dx[board[i][j][0].dir];
					br = true;
					if (!inRange(ny, nx) || tiles[ny][nx] == 2)
					{
						board[i][j][0].dir = getOppDir(board[i][j][0].dir);
						ny = i + dy[board[i][j][0].dir]; nx = j + dx[board[i][j][0].dir];
						if (!inRange(ny, nx) || tiles[ny][nx] == 2) continue;
						if (tiles[ny][nx] == 0)
						{
							for (int idx = 0; idx < board[i][j].size(); idx++)
								board[ny][nx].push_back(board[i][j][idx]);
							board[i][j] = vector<token>();
							continue;
						}
						else
						{
							while (!board[i][j].empty())
							{
								board[ny][nx].push_back(board[i][j].back());
								board[i][j].pop_back();
							}
						}

					}
					if (tiles[ny][nx] == 1)
						while (!board[i][j].empty())
						{
							board[ny][nx].push_back(board[i][j].back());
							board[i][j].pop_back();
						}
					if (tiles[ny][nx] == 0)
					{
						for (int idx = 0; idx < board[i][j].size(); idx++)
							board[ny][nx].push_back(board[i][j][idx]);
						board[i][j] = vector<token>();
					}
				}
			}
		}
		if (isGameEnd()) break;
	}
	if (!isGameEnd()) turn = -1;
	cout << turn << '\n';
}

// https://www.acmicpc.net/problem/17780