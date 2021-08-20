#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int N, M, ans = 0; char w;
vector<vector<int>> pool;

bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y <= N + 1 && x <= M + 1);
}
void bfs(int h)
{
	vector<vector<bool>> v(N + 2, vector<bool>(M + 2, false));
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	v[0][0] = true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || v[ny][nx] || pool[ny][nx] >= h) continue;
			pool[ny][nx] = h;
			v[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	pool.resize(N + 2, vector<int>(M + 2));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> w;
			pool[i][j] = w - '0';
		}
	for (int h = 1; h <= 9; h++)
	{
		bfs(h);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
			{
				if (pool[i][j] < h)
				{
					ans++;
					pool[i][j]++;
				}
			}
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1113