#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
struct Direction
{
	int dir;
	Direction()
	{
		dir = 0;
	}
	void rotateClockwise()
	{
		dir++;
		if (dir > 3) dir = 0;
	}
	void rotateAntiClockwise()
	{
		dir--;
		if (dir < 0) dir = 3;
	}
	void setOppositeDir()
	{
		if (dir < 2) dir += 2;
		else dir -= 2;
	}
	int getNewY(int y)
	{
		return dy[dir] + y;
	}
	int getNewX(int x)
	{
		return dx[dir] + x;
	}
};

struct Dice
{
	int faces[4] = { 1, 5, 6, 2 };
	int sides[4] = { 1, 3, 6, 4 };
	int getBelow()
	{
		return faces[2];
	}
	void rollEast()
	{
		int tmp[4];
		tmp[0] = sides[3];
		for (int i = 0; i < 3; i++)
			tmp[i + 1] = sides[i];
		faces[0] = tmp[0];
		faces[2] = tmp[2];
		for (int i = 0; i < 4; i++)
			sides[i] = tmp[i];
	}
	void rollWest()
	{
		int tmp[4];
		tmp[3] = sides[0];
		for (int i = 0; i < 3; i++)
			tmp[i] = sides[i + 1];
		faces[0] = tmp[0];
		faces[2] = tmp[2];
		for (int i = 0; i < 4; i++)
			sides[i] = tmp[i];
	}
	void rollNorth()
	{
		int tmp[4];
		tmp[3] = faces[0];
		for (int i = 0; i < 3; i++)
			tmp[i] = faces[i + 1];
		sides[0] = tmp[0];
		sides[2] = tmp[2];
		for (int i = 0; i < 4; i++)
			faces[i] = tmp[i];
	}
	void rollSouth()
	{
		int tmp[4];
		tmp[0] = faces[3];
		for (int i = 0; i < 3; i++)
			tmp[i + 1] = faces[i];
		sides[0] = tmp[0];
		sides[2] = tmp[2];
		for (int i = 0; i < 4; i++)
			faces[i] = tmp[i];
	}
	void rollDice(Direction* d)
	{
		switch (d->dir)
		{
		case 0:
			rollEast();
			break;
		case 1:
			rollSouth();
			break;
		case 2:
			rollWest();
			break;
		case 3:
			rollNorth();
			break;
		}
	}
};


struct Board
{
	vector<vector<int>> board, score;
	Dice* dice;
	Direction* direction;
	int Ver, Hor;
	pair<int, int> pos;
	Board(int N, int M)
	{
		dice = new Dice();
		direction = new Direction();
		Ver = N; Hor = M;
		board.resize(N, vector<int>(M));
		score.resize(N, vector<int>(M, -1));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> board[i][j];
		pos = make_pair(0, 0);
		setScore();
	}
	void setScore()
	{
		for (int i = 0; i < Ver; i++)
			for (int j = 0; j < Hor; j++)
				if (score[i][j] == -1)
					score[i][j] = getScore(i, j);
	}
	bool inRange(int y, int x)
	{
		return y >= 0 && x >= 0 && y < Ver && x < Hor;
	}
	int getScore(int y, int x)
	{
		vector<vector<bool>> v(Ver, vector<bool>(Hor, false));
		queue<pair<int, int>> q;
		v[y][x] = true;
		q.push({ y, x });
		int ret = board[y][x];
		while (!q.empty())
		{
			int _y = q.front().first;
			int _x = q.front().second;
			q.pop();
			for (int d = 0; d < 4; d++)
			{
				int ny = _y + dy[d];
				int nx = _x + dx[d];
				if (!inRange(ny, nx) || v[ny][nx] || board[y][x] != board[ny][nx]) continue;
				if (score[ny][nx] != -1) return score[ny][nx];
				v[ny][nx] = true;
				ret += board[y][x];
				q.push({ ny, nx });
			}
		}
		return ret;
	}
	int play(int cnt)
	{
		int ret = 0;
		for (int k = 0; k < cnt; k++)
		{
			int ny = direction->getNewY(pos.first);
			int nx = direction->getNewX(pos.second);
			if (!inRange(ny, nx))
			{
				direction->setOppositeDir(); k--;
				continue;
			}
			dice->rollDice(direction);
			ret += score[ny][nx];
			pos = make_pair(ny, nx);
			if (dice->getBelow() > board[ny][nx])
				direction->rotateClockwise();
			if (dice->getBelow() < board[ny][nx])
				direction->rotateAntiClockwise();
		}
		return ret;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	Board* board = new Board(N, M);
	cout << board->play(K) << '\n';
}
// https://www.acmicpc.net/problem/23288