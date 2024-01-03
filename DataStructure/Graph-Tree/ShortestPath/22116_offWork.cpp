#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int A[1001][1001];
int N, R, C, ans = 0, D[1001][1001];
int dy[4] = { -1, 1, 0,0 };
int dx[4] = { 0, 0, -1, 1 };

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
			D[i][j] = 1000000007;
		}
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0, {0, 0} });
	D[0][0] = 0;
	while (!pq.empty())
	{
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();
		if (D[y][x] < cost) continue;
		if (y == N - 1 && x == N - 1)
		{
			ans = cost;
			break;
		}
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx)) continue;
			int nc = max(abs(A[ny][nx] - A[y][x]), cost);
			if (nc >= D[ny][nx]) continue;
			D[ny][nx] = nc;
			pq.push({ -nc, {ny, nx} });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/22116