#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <queue>

using namespace std;

int W = 0;

int getNum(pair<int, int> pos)
{
	return pos.first * W + pos.second;
}

pair<int, int> operator+(pair<int, int> p1, pair<int, int> p2)
{
	return make_pair(p1.first + p2.first, p1.second + p2.second);
}

int minTime(vector<list<int>> near, int start, int end, int size)
{
	queue<pair<int, int>> q;
	vector<bool> visited(size + 1, false);
	q.push(make_pair(start, 0));
	visited[start] = true;

	while (!q.empty())
	{
		// cout << "visited: " << q.front().first << endl;
		for (int n : near[q.front().first])
		{
			if (n == end)
			{
				return q.front().second + 1;
			}
			if (!visited[n])
			{
				visited[n] = true;
				q.push(make_pair(n, q.front().second + 1));
			}
		}
		q.pop();
	}

	return 0;
}
const pair<int, int> east = make_pair(0, 1);
const pair<int, int> west = make_pair(0, -1);
const pair<int, int> south = make_pair(1, 0);
const pair<int, int> north = make_pair(-1, 0);
const vector<pair<int, int>> news = { north, west, east, south };

int main(void)
{
	vector<string> map;

	int h, w, n;
	cin >> h >> w >> n;

	vector<int> cheese(n + 1);
	vector<list<int>> graph(h * w);

	W = w;

	for (int i = 0; i < h; i++)
	{
		string tmp;
		cin >> tmp;
		map.push_back(tmp);
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			pair<int, int> pos = make_pair(i, j);
			list<int> connect;

			if (map[i][j] == 'X')
				continue;
			else if (map[i][j] == 'S')
				cheese[0] = getNum(pos);
			else if (map[i][j] == '.') {}
			else
				cheese[map[i][j] - '0'] = getNum(pos);

			for (int dir = 0; dir < news.size(); dir++)
			{
				pair<int, int> near = pos + news[dir];
				if (near.first < 0 || near.second < 0 || near.first >= h || near.second >= w)
					continue;
				if (map[near.first][near.second] != 'X')
					graph[getNum(pos)].push_back(getNum(near));
			}
		}
	}

	int answer = 0;
	for (int c = 0; c < cheese.size() - 1; c++)
	{
		answer += minTime(graph, cheese[c], cheese[c + 1], h * w);
	}

	cout << answer << endl;
	return 0;
}
// https://www.acmicpc.net/problem/5558