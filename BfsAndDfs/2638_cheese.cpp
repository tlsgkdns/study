#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, tmp, ans, s = 0;
vector<vector<bool>> paper;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main()
{
	cin >> n >> m;
	pair<int, int> edge[4] = { {0, 0}, {n - 1, 0}, {0, m - 1}, {n - 1, m - 1} };
	paper.resize(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			if (tmp == 0) paper[i][j] = false;
			else
			{
				paper[i][j] = true;
				s++;
			}
		}
	pair<int, int> start;
	for (int i = 0; i < 4; i++)
		if (paper[edge[i].first][edge[i].second] == 0)
		{
			start = edge[i];
			break;
		}
	while (true)
	{
		if (s <= 0) break;
		queue<pair<int, int>> q;
		q.push(start);
		vector<vector<bool>> v(n, vector<bool>(m, false));
		vector<vector<int>> air(n, vector<int>(m, 0));
		vector<pair<int, int>> cheese;
		v[start.first][start.second] = true;
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny == n || nx == m) continue;
				if (paper[ny][nx] == true)
				{
					air[ny][nx]++;
					if (air[ny][nx] == 2)
						cheese.push_back({ ny, nx });
					continue;
				}
				if (v[ny][nx]) continue;
				v[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
		for (pair<int, int> ch : cheese)
		{
			paper[ch.first][ch.second] = false;
			s--;
		}
		ans++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2638