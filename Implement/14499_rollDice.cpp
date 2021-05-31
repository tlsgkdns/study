#include <iostream>
#include <vector>
using namespace std;

int N, M, X, Y, K, C;

vector<vector<int>> board;
vector<int> ans;

int dy[5] = { -10, 0, 0, -1, 1 };
int dx[5] = { -10, 1, -1, 0, 0 };

struct Dice
{
	int verSide[4] = { 0, 0, 0, 0 };
	int horSide[4] = { 0, 0, 0, 0 };
	int x, y;

	Dice(int x_, int y_)
	{
		x = x_;
		y = y_;
	}
	void rollNorth()
	{
		int tmp = horSide[0];
		for (int i = 0; i < 3; i++)
			horSide[i] = horSide[i + 1];
		horSide[3] = tmp;
		verSide[1] = horSide[1];
		verSide[3] = horSide[3];
	}
	void rollSouth()
	{
		for (int i = 0; i < 3; i++)
			rollNorth();
	}
	void rollWest()
	{
		int tmp = verSide[0];
		for (int i = 0; i < 3; i++)
			verSide[i] = verSide[i + 1];
		verSide[3] = tmp;
		horSide[1] = verSide[1];
		horSide[3] = verSide[3];
	}
	void rollEast()
	{
		for (int i = 0; i < 3; i++)
			rollWest();
	}
	void setBottom()
	{
		if (board[y][x] == 0)
			board[y][x] = horSide[3];
		else
		{
			horSide[3] = verSide[3] = board[y][x];
			board[y][x] = 0;
		}

	}
	int getTop()
	{
		return verSide[1];
	}
	int moveDice(int cmd)
	{
		int ny = y + dy[cmd];
		int nx = x + dx[cmd];
		if (ny < 0 || nx < 0 || ny > N - 1 || nx > M - 1) return -1;
		y = ny;
		x = nx;
		return rollDice(cmd);
	}
	int rollDice(int cmd)
	{
		switch (cmd)
		{
		case 1:
			rollEast();
			break;
		case 2:
			rollWest();
			break;
		case 3:
			rollNorth();
			break;
		case 4:
			rollSouth();
			break;
		}
		setBottom();
		return getTop();
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> X >> Y >> K;
	board.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	Dice d(Y, X);
	for (int i = 0; i < K; i++)
	{
		cin >> C;
		int res = d.moveDice(C);
		if (res < 0) continue;
		ans.push_back(res);
	}
	for (int a : ans)
		cout << a << '\n';
}

//https://www.acmicpc.net/problem/14499