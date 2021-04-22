#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<vector<int>> space;
int n;
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

int main()
{
	pair<int, int> start;
	cin >> n;
	space.resize(n, vector<int>(n));
	vector<vector<bool>> v(n, vector<bool>(n, false));
	vector<int> fish(7, 0);
	int zero = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 9) { space[i][j] = 0; start = make_pair(i, j); continue; }
			if (space[i][j] != 0) fish[space[i][j]]++;
		}

	int ans = 0;
	queue<tuple<int, int, int>> pos;
	int size = 2;
	int ate = 0;
	int remain = fish[size - 1];
	vector<tuple<int, int, int>> tmp;

	pos.push(make_tuple(start.first, start.second, 0));
	v[start.first][start.second] = true;
	while (true)
	{
		if (pos.empty())
		{
			if (tmp.empty()) break;
			sort(tmp.begin(), tmp.end(), greater<tuple<int, int, int>>());
			while (!tmp.empty())
			{
				pos.push(tmp.back());
				tmp.pop_back();
			}
		}

		int y = get<0>(pos.front());
		int x = get<1>(pos.front());
		int t = get<2>(pos.front());
		if (remain == 0)
		{
			ans = t; break;
		}

		if (space[y][x] != 0 && space[y][x] < size)
		{
			ans = t;
			space[y][x] = 0;
			while (!pos.empty()) pos.pop();
			fill(v.begin(), v.end(), vector<bool>(n, false));
			v[y][x] = true;
			ate++; pos.push(make_tuple(y, x, t));
			if (ate == size) { size++; ate = 0; if (size < 8) remain += fish[size - 1]; }
			tmp.clear();
			continue;
		}
		pos.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny == n || nx == n ||
				space[ny][nx] > size || v[ny][nx]) continue;

			v[ny][nx] = true;
			tmp.push_back(make_tuple(ny, nx, t + 1));
		}
	}

	cout << ans << endl;
}

// https://www.acmicpc.net/problem/16236