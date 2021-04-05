#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, d, enemy = 0, ans = -1;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
void defense(vector<vector<int>> map, vector<int>& pos)
{
	int eNum = enemy; int shot = 0;
	while (eNum > 0)
	{
		pair<int, int> target[3] = { {-1, -1},{-1, -1},{-1, -1} };
		for (int p = 0; p < pos.size(); p++)
		{
			priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
				greater<pair<int, pair<int, int>>>> pq;
			vector<vector<bool>> v(n + 1, vector<bool>(m, false));
			pq.push(make_pair(0, make_pair(pos[p], n)));
			v[n][pos[p]] = true;
			while (!pq.empty())
			{
				bool end = false;
				int dist = pq.top().first;
				int x = pq.top().second.first;
				int y = pq.top().second.second;
				pq.pop();
				for (int i = 0; i < 4; i++)
				{
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny < 0 || nx < 0 || ny > n || nx >= m || v[ny][nx]) continue;
					if (map[ny][nx] == 1)
					{
						if (d > dist) target[p] = make_pair(ny, nx);
						end = true;
						break;
					}
					v[ny][nx] = true;
					pq.push(make_pair(dist + 1, make_pair(nx, ny)));
				}
				if (end) break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (target[i].first > n || target[i].first < 0) continue;
			if (map[target[i].first][target[i].second] == 1)
			{
				shot++;
				eNum--;
			}
			map[target[i].first][target[i].second] = 0;
		}
		for (int i = n - 1; i >= 0; i--)
			for (int j = 0; j < m; j++)
				if (map[i][j] == 1)
				{
					map[i][j] = 0;
					if (i + 1 == n)
					{
						eNum--;
						continue;
					}
					map[i + 1][j] = 1;
				}
	}
	ans = max(shot, ans);
}

void deploy(vector<vector<int>>& map, vector<int>& pos)
{
	if (pos.size() == 3)
	{
		defense(map, pos);
		return;
	}
	for (int i = 0; i < m; i++)
	{
		if (map[n][i] == 3) continue;
		map[n][i] = 3;
		pos.push_back(i);
		deploy(map, pos);
		map[n][i] = 2;
		pos.pop_back();
	}
}

int main()
{
	cin >> n >> m >> d;
	vector<vector<int>> map(n + 1, vector<int>(m)); // 0, ºóÅÍ, 1, Àû, 2. ¼º, 3. ±Ã¼ö°¡ ÀÖ´Â °÷.
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) enemy++;
		}
	for (int i = 0; i < m; i++)
		map[n][i] = 2;
	vector<int> pos;
	deploy(map, pos);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17135

/*
Difficult implement problem.
*/