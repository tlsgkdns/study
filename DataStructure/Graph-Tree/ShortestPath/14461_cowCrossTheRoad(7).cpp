#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

const int INF = 1000000007;
int N, T, D[101][101][3], G[101][101], ans = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> G[i][j];
			for (int k = 0; k < 3; k++)
				D[i][j][k] = INF;
		}
	priority_queue<pair<int, pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {0, {0, 0}} });
	D[0][0][0] = 0;
	while (!pq.empty())
	{
		int y = pq.top().second.second.first;
		int x = pq.top().second.second.second;
		int c = pq.top().second.first;
		int cost = -pq.top().first;
		pq.pop();
		if (D[y][x][c] < cost) continue;
		if (y == N - 1 && x == N - 1)
		{
			ans = cost;
			break;
		}
		int nc = (c + 1) % 3;
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny > N || nx > N) continue;
			int nxtCost = cost + T + ((nc == 0) ? G[ny][nx] : 0);
			if (D[ny][nx][nc] > nxtCost)
			{
				D[ny][nx][nc] = nxtCost;
				pq.push({ -nxtCost, {nc, {ny, nx}} });
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14461