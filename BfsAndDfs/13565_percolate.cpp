#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool grid[1001][1001], v[1001][1001];
char ch;
int N, M;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool ans = false;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y <= N && x < M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(grid, true, sizeof(grid));
	memset(v, false, sizeof(v));
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch == '1') grid[i][j] = false;
		}
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	v[0][0] = true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == N)
		{
			ans = true;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || v[ny][nx] || !grid[ny][nx]) continue;
			v[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
	if (ans) cout << "YES\n"; else cout << "NO\n";
}

// https://www.acmicpc.net/problem/13565