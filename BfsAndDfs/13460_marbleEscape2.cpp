#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using p = pair<int, int>;

vector<vector<char>> maze;
p redPos, bluePos, dst;
int n, m;
char c;
p d[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
p operator+(p p1, p p2)
{
	return make_pair(p1.first + p2.first, p1.second + p2.second);
}
p operator-(p p1, p p2)
{
	return make_pair(p1.first - p2.first, p1.second - p2.second);
}
p tilt(p pos, p plus, p opp)
{
	bool mv = false;
	while (maze[pos.first][pos.second] != '#' && pos != opp &&
		maze[pos.first][pos.second] != 'O')
	{
		pos = pos + plus;
		mv = true;
	}
	if (mv) pos = pos - plus;
	return pos;
}
int bfs()
{
	queue<pair<pair<p, p>, int>> q;
	q.push(make_pair(make_pair(redPos, bluePos), 1));
	while (!q.empty())
	{
		p red = q.front().first.first;
		p blue = q.front().first.second;
		int move = q.front().second;
		q.pop();
		if (move > 10) return -1;
		for (int i = 0; i < 4; i++)
		{
			bool esp = false;
			p nr = tilt(red, d[i], blue);
			if (nr + d[i] == dst) esp = true;
			p nb = tilt(blue, d[i], (esp) ? make_pair(0, 0) : nr);
			if (nb + d[i] == dst) continue;
			nr = tilt(nr, d[i], nb);
			if (nr + d[i] == dst) return move;
			q.push(make_pair(make_pair(nr, nb), move + 1));
		}
	}
}
int main()
{
	cin >> n >> m; maze.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 'B')
				bluePos = { i, j };
			else if (maze[i][j] == 'R')
				redPos = { i, j };
			else if (maze[i][j] == 'O')
				dst = { i, j };
		}
	cout << bfs() << '\n';
}

// https://www.acmicpc.net/problem/13460

/*
Complicate BFS implementing problem.
*/