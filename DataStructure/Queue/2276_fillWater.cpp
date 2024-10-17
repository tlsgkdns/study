#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

priority_queue<pair<int, pair<int, int>>> pq;
int H[302][302], N, M, ans = 0;
bool v[302][302];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y > 0 && x > 0 && y <= N && x <= M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> H[i][j];
			if (i == 1 || j == 1 || j == M || i == N)
			{
				v[i][j] = true;
				pq.push({ -H[i][j], {i, j} });
			}
		}
	while (!pq.empty())
	{
		int h = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || v[ny][nx]) continue;
			v[ny][nx] = true;
			if (H[ny][nx] > h) pq.push({ {-H[ny][nx]}, {ny, nx} });
			else
			{
				ans += h - H[ny][nx];
				pq.push({ -h, {ny, nx} });
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2276