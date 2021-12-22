#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

pair<int, int> start = { -1, -1 };
int N, M;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<vector<int>> course, waypoint;

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
bool bfs(int sub)
{
	vector<vector<bool>> v(N, vector<bool>(M, false));
	queue<pair<int, int>> q;
	q.push(start);
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
			if (!inRange(ny, nx) || v[ny][nx] || abs(course[y][x] - course[ny][nx]) >= sub) continue;
			v[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (waypoint[i][j] == 1 && !v[i][j])
				return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	course.resize(N, vector<int>(M));
	waypoint.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> course[i][j];
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> waypoint[i][j];
			if (start.first == -1 && waypoint[i][j] == 1)
				start = { i, j };
		}
	int l = 0, r = 1000000001;
	for (int it = 0; it < 32; it++)
	{
		int m = (l + r) / 2;
		if (bfs(m)) r = m;
		else l = m;
	}
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/9879