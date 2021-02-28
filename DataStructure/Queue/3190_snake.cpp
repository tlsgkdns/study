#include <iostream>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

deque<pair<int, int>> mv;
queue<pair<int, int>> snake;
vector<vector<int>> b;

void lookLeft()
{
	auto b = mv.back();
	mv.pop_back();
	mv.push_front(b);
}
void lookRight()
{
	auto f = mv.front();
	mv.pop_front();
	mv.push_back(f);
}
int main()
{
	mv.push_back(make_pair(0, 1));
	mv.push_back(make_pair(1, 0));
	mv.push_back(make_pair(0, -1));
	mv.push_back(make_pair(-1, 0));

	int n, k, l;
	queue<pair<int, bool>>trans;
	cin >> n;
	b.resize(n, vector<int>(n, 0));
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int y, x;
		cin >> y >> x;
		b[y - 1][x - 1] = 2;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int x; char c;
		cin >> x >> c;
		bool b = (c == 'D') ? true : false;
		trans.push(make_pair(x, b));
	}
	snake.push({ 0, 0 });
	b[0][0] = 1;
	int time = 0;

	while (true)
	{
		if (!trans.empty() && trans.front().first == time)
		{
			if (trans.front().second) lookRight();
			else lookLeft();
			trans.pop();
		}
		auto nxt = make_pair(snake.back().first + mv.front().first, snake.back().second + mv.front().second);
		time++;
		if (nxt.first < 0 || nxt.second < 0 ||
			nxt.first >= n || nxt.second >= n || b[nxt.first][nxt.second] == 1) break;
		snake.push(nxt);
		if (b[nxt.first][nxt.second] == 0)
		{
			b[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}
		b[nxt.first][nxt.second] = 1;
	}
	cout << time << endl;
}

// https://www.acmicpc.net/problem/3190

/*
interesting simulate problem with depue.
*/