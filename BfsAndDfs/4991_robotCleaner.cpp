#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
const int INF = 1000000000;

int main()
{
	vector<int> ans;
	int h, w;
	while (true)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);
		cin >> w >> h;
		if (h == 0 && w == 0) break;
		vector<vector<char>> room(h, vector<char>(w));
		vector<pair<int, int>> dirt;
		pair<int, int> start;
		int a = INF;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				cin >> room[i][j];
				if (room[i][j] == '*') dirt.push_back({ i, j });
				if (room[i][j] == 'o') start = { i, j };
			}
		sort(dirt.begin(), dirt.end());
		queue<pair<pair<int, int>, pair<int, int>>> q;
		q.push({ start, make_pair(0, 0) });
		vector<vector<vector<bool>>> v(h, vector<vector<bool>>(w, vector<bool>((1 << 10) + 1, false)));
		v[start.first][start.second][0] = true;
		while (!q.empty())
		{
			int y = q.front().first.first;
			int x = q.front().first.second;
			int cnt = q.front().second.first;
			int t = q.front().second.second;
			q.pop();
			if (t == (1 << dirt.size()) - 1)
			{
				a = min(a, cnt);
				continue;
			}
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w || v[ny][nx][t] || room[ny][nx] == 'x') continue;
				v[ny][nx][t] = true;
				int nt = t;
				if (binary_search(dirt.begin(), dirt.end(), make_pair(ny, nx)))
				{
					int it = lower_bound(dirt.begin(), dirt.end(), make_pair(ny, nx)) - dirt.begin();
					nt |= (1 << it);
				}
				v[ny][nx][nt] = true;
				q.push(make_pair(make_pair(ny, nx), make_pair(cnt + 1, nt)));
			}
		}
		if (a == INF) a = -1;
		ans.push_back(a);
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/4991