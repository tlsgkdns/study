#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> ans;
int land[12][12];
int T, R, C;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0 , 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y <= R + 1 && x <= C + 1;
}
void bfs(int h)
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || land[ny][nx] >= h) continue;
			land[ny][nx] = h;
			q.push({ ny, nx });
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> R >> C;
		memset(land, 0, sizeof(land));
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				cin >> land[i][j];
		int a = 0;
		for (int h = 1; h <= 1000; h++)
		{
			bfs(h);
			for (int i = 1; i <= R; i++)
				for (int j = 1; j <= C; j++)
					if (land[i][j] < h)
					{
						a++;
						land[i][j]++;
					}
		}
		ans.push_back(a);
	}
	for (int t = 1; t <= T; t++)
		cout << "Case #" << t << ": " << ans[t - 1] << '\n';
}

// https://www.acmicpc.net/problem/14324