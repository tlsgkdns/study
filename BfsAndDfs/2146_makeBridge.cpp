#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int N;
vector<vector<int>> land, group;
bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < N && x < N);
}
int bfs(int num)
{
	vector<vector<int>> v(N, vector<int>(N, -1));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (group[i][j] == num)
			{
				v[i][j] = 0;
				q.push({ i, j });
			}
	int ret = -1;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (ret != -1) break;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || v[ny][nx] != -1) continue;
			if (land[ny][nx])
			{
				if (group[ny][nx] != num)
					ret = v[y][x];
				continue;
			}
			v[ny][nx] = v[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	return ret;
}
void dfs(int y, int x, int n)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!inRange(ny, nx) || !land[ny][nx] || group[ny][nx] != -1) continue;
		group[ny][nx] = n;
		dfs(ny, nx, n);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	land.resize(N, vector<int>(N));
	group.resize(N, vector<int>(N, -1));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> land[i][j];
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (land[i][j] && group[i][j] == -1)
			{
				cnt++;
				group[i][j] = cnt;
				dfs(i, j, cnt);
			}
		}
	int ans = 100000;
	for (int n = 1; n <= cnt; n++)
		ans = min(bfs(n), ans);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2146