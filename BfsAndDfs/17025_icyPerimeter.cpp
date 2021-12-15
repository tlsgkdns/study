#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, area = -1, perimeter = -1;
vector<vector<char>> ice;
vector<vector<bool>> v;
bool inRange(int y, int x)
{
	return y > 0 && x > 0 && y <= N && x <= N;
}
void bfs(int sy, int sx)
{
	queue<pair<int, int>> q;
	q.push({ sy, sx }); v[sy][sx] = true;
	int per = 0, ar = 1;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || ice[ny][nx] == '.')
			{
				per++;
				continue;
			}
			if (v[ny][nx]) continue;
			v[ny][nx] = true; ar++;
			q.push({ ny, nx });
		}
	}
	v;
	if (area == ar) perimeter = min(perimeter, per);
	if (ar > area)
	{
		area = ar;
		perimeter = per;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	ice.resize(N + 1, vector<char>(N + 1, '.'));
	v.resize(N + 1, vector<bool>(N + 1, false));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> ice[i][j];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (ice[i][j] == '#' && !v[i][j])
				bfs(i, j);
	cout << area << " " << perimeter << '\n';
}

// https://www.acmicpc.net/problem/17025