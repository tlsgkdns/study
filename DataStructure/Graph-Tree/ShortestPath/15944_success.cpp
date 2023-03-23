#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
int N, M, D, ans = 0;
char P[501][501];
int v[501][501];
int dy[4] = { -1 , 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<int> dy2, dx2;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N&& x < M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> P[i][j];
			v[i][j] = INF;
		}
	for (int i = -D; i <= D; i++)
		for (int j = -D; j <= D; j++)
		{
			if (abs(i) == abs(j) && abs(i) == D) continue;
			if (abs(i) != D && abs(j) != D && abs(i) != 0 && abs(j) != 0) continue;
			dy2.push_back(i); dx2.push_back(j);
		}
	v[0][0] = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0, {0, 0} });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (v[y][x] < cost) continue;
		if (y == N - 1 && x == M - 1)
		{
			ans = v[y][x];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || v[ny][nx] <= cost || P[ny][nx] == '#') continue;
			v[ny][nx] = cost;
			pq.push({ -cost, {ny, nx} });
		}
		for (int i = 0; i < dx2.size(); i++)
		{
			int ny = max(0, min(N - 1, y + dy2[i]));
			int nx = max(0, min(M - 1, x + dx2[i]));
			if (!inRange(ny, nx) || v[ny][nx] <= cost + 1) continue;
			v[ny][nx] = cost + 1;
			pq.push({ -(cost + 1), {ny, nx} });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15944