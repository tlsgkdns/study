#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C, G[1001][1001], N, rs, cs, rd, cd, D[1001][1001];
char ch;
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
bool inRange(int y, int x)
{
	return y > 0 && x > 0 && y <= R && x <= C;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			cin >> ch;
			G[i][j] = (ch - '0');
		}
	cin >> N;
	while (N--)
	{
		for (int r = 1; r <= R; r++)
			for (int c = 1; c <= C; c++)
				D[r][c] = 1000000007;
		cin >> rs >> cs >> rd >> cd;
		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({ 0, {rs, cs } });
		D[rs][cs] = 0;
		while (!pq.empty())
		{
			int y = pq.top().second.first;
			int x = pq.top().second.second;
			int cost = -pq.top().first;
			pq.pop();
			if (y == rd && x == cd) break;
			for (int d = 0; d < 8; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (inRange(ny, nx))
				{
					if (G[y][x] == d)
					{
						if (D[ny][nx] <= D[y][x]) continue;
						D[ny][nx] = D[y][x];
						pq.push({ -D[ny][nx], {ny, nx} });
					}
					else
					{
						if (D[ny][nx] <= D[y][x] + 1) continue;
						D[ny][nx] = D[y][x] + 1;
						pq.push({ -(D[ny][nx] + 1), {ny, nx} });
					}
				}
			}
		}
		cout << D[rd][cd] << '\n';
	}
}

// https://www.acmicpc.net/problem/4184