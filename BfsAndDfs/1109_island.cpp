#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
int ans[2500];
vector<vector<char>> maps;
vector<vector<int>> group;
vector<vector<bool>> v;
vector<int> height;
vector<bool> gv;
int N, M, G = 0, mx = -1;
int dy1[4] = { 0, 0, -1, 1 };
int dx1[4] = { 1, -1, 0, 0 };
int dy2[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dx2[8] = { 0, 1, -1, 1, -1, -1, 0, 1 };
int fillLand(int, int);
int fillSea(int, int);
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y <= N + 1 && x <= M + 1;
}
void dfs(int y, int x, const int g)
{
	for (int d = 0; d < 8; d++)
	{
		int ny = y + dy2[d];
		int nx = x + dx2[d];
		if (!inRange(ny, nx) || maps[ny][nx] == '.' || group[ny][nx] != -1) continue;
		group[ny][nx] = g;
		dfs(ny, nx, g);
	}
}

int fillSea(int sy, int sx)
{
	vector<pii> arr;
	queue<pii> q;
	q.push({ sy, sx });
	v[sy][sx] = true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy1[d];
			int nx = x + dx1[d];
			if (!inRange(ny, nx) || v[ny][nx]) continue;
			if (maps[ny][nx] == 'x')
			{
				if (gv[group[ny][nx]]) continue;
				gv[group[ny][nx]] = true;
				arr.push_back({ ny, nx });
			}
			else
			{
				v[ny][nx] = true;
				q.push({ ny, nx });
			}

		}
	}
	int ret = -1;
	for (int i = 0; i < arr.size(); i++)
		ret = max(fillLand(arr[i].first, arr[i].second), ret);
	return ret;
}
int fillLand(int sy, int sx)
{
	int h = 0;
	queue<pii> q;
	q.push({ sy, sx });
	v[sy][sx] = true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 8; d++)
		{
			int ny = y + dy2[d];
			int nx = x + dx2[d];
			if (!inRange(ny, nx) || v[ny][nx]) continue;
			if (maps[ny][nx] == '.')
				h = max(fillSea(ny, nx) + 1, h);
			else
			{
				v[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
	height[group[sy][sx]] = h; mx = max(mx, h);
	return h;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(ans, 0, sizeof(ans));
	cin >> N >> M;
	maps.resize(N + 2, vector<char>(M + 2, '.'));
	v.resize(N + 2, vector<bool>(M + 2, false)); group.resize(N + 2, vector<int>(M + 2, -1));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> maps[i][j];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (maps[i][j] == '.' || group[i][j] != -1) continue;
			group[i][j] = G;
			dfs(i, j, G++);
		}
	height.resize(G); gv.resize(G);
	fillSea(0, 0);
	for (int h : height) ans[h]++;
	if (mx == -1) cout << -1 << '\n';
	else
	{
		for (int i = 0; i <= mx; i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/1109