#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, pair<int, int>>> pq;
bool nearWall[501][501], wall[501][501];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int H, W, D[501][501];
char G[501][501];
pair<int, int> dst;
int inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < H && x < W;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> H >> W;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> G[i][j];
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			D[i][j] = 1000000007;
			if (G[i][j] == 'S')
			{
				D[i][j] = 0;
				pq.push({ 0, {i, j} });
			}
			if (G[i][j] == 'E')
			{
				dst = { i, j };
			}
			if (G[i][j] == '#')
			{
				wall[i][j] = true;
			}
			else
			{
				bool f = false;
				for (int d = 0; d < 4; d++)
				{
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (!inRange(ny, nx)) continue;
					if (G[ny][nx] == '#')
					{
						f = true;
						break;
					}
				}
				nearWall[i][j] = f;
			}
		}
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (D[y][x] < cost) continue;
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || wall[ny][nx]) continue;
			int add = !(nearWall[y][x] && nearWall[ny][nx]);
			if (D[ny][nx] > cost + add)
			{
				D[ny][nx] = cost + add;
				pq.push({ -(cost + add), {ny, nx} });
			}
		}
	}
	cout << D[dst.first][dst.second] << '\n';
}

// https://www.acmicpc.net/problem/23563