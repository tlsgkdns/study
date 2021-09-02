#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[5] = { 0, 0, 0, 1, -1 };
int dx[5] = { 0, 1, -1, 0, 0 };
vector<vector<int>> world;
vector<vector<vector<int>>> v;
int M, N;

vector<int> getRot(int d)
{
	if (d == 3 || d == 4) return { 1, 2 };
	else return { 3, 4 };
}
bool inRange(int y, int x)
{
	return (y >= 1 && x >= 1 && y <= M && x <= N);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	world.resize(M + 1, vector<int>(N + 1));
	v.resize(M + 1, vector<vector<int>>(N + 1, vector<int>(5, -1)));
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			cin >> world[i][j];
	queue<pair<pair<int, int>, int>> q;
	int sy, sx, sd, ey, ex, ed;
	cin >> sy >> sx >> sd;
	cin >> ey >> ex >> ed;
	v[sy][sx][sd] = 0;
	q.push(make_pair(make_pair(sy, sx), sd));
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if (y == ey && x == ex && d == ed) break;
		for (int k = 1; k <= 3; k++)
		{
			int ny = dy[d] * k + y;
			int nx = dx[d] * k + x;
			if (!inRange(ny, nx) || v[ny][nx][d] != -1) continue;
			if (world[ny][nx] == 1) break;
			v[ny][nx][d] = v[y][x][d] + 1;
			q.push(make_pair(make_pair(ny, nx), d));
		}
		for (int nd : getRot(d))
		{
			if (v[y][x][nd] != -1) continue;
			v[y][x][nd] = v[y][x][d] + 1;
			q.push(make_pair(make_pair(y, x), nd));
		}
	}
	cout << v[ey][ex][ed] << '\n';
}
// https://www.acmicpc.net/problem/1726