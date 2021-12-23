#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> garden;
vector<pair<int, int>> points;

int N, M, G, R, ans = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}

int bfs(vector<int>& cult)
{
	vector<vector<int>> v(N, vector<int>(M, -1)), water(N, vector<int>(M, -1));
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < cult.size(); i++)
	{
		if (cult[i] == 0) continue;
		v[points[i].first][points[i].second] = 0;
		water[points[i].first][points[i].second] = cult[i];
		q.push(make_pair(points[i], cult[i]));
	}
	int ret = 0;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int k = q.front().second;
		q.pop();
		if (water[y][x] == 3) continue;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || garden[ny][nx] == 0) continue;
			if (v[ny][nx] == v[y][x] + 1 && water[ny][nx] == 3 - k)
			{
				ret++;
				water[ny][nx] = 3;
			}
			else
			{
				if (v[ny][nx] != -1) continue;
				v[ny][nx] = v[y][x] + 1;
				water[ny][nx] = k;
				q.push(make_pair(make_pair(ny, nx), k));
			}
		}
	}
	if (ret == 6)
	{
		water;
		cult; v;
		int a = 0;
	}

	return ret;
}

void solve(vector<int>& clt, int r, int g)
{
	if (clt.size() == points.size())
	{
		if (r == 0 && g == 0) ans = max(ans, bfs(clt));
		return;
	}
	if (r > 0)
	{
		clt.push_back(1);
		solve(clt, r - 1, g);
		clt.pop_back();
	}
	if (g > 0)
	{
		clt.push_back(2);
		solve(clt, r, g - 1);
		clt.pop_back();
	}
	clt.push_back(0);
	solve(clt, r, g);
	clt.pop_back();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> G >> R;
	garden.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> garden[i][j];
			if (garden[i][j] == 2) points.push_back({ i, j });
		}
	vector<vector<int>> cult(N, vector<int>(M, -1));
	vector<int> cl2;
	solve(cl2, R, G);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/18809