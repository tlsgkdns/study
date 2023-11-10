#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, K, S[1002][1002], L = 0, R = 1000000007;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool v[1002][1002];
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y <= N && x <= M + 1;
}
bool solve(int D)
{
	memset(v, false, sizeof(v));
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	int cnt = 0;
	v[0][0] = true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || v[ny][nx] || S[ny][nx] > D) continue;
			v[ny][nx] = true;
			cnt += (S[ny][nx] > 0);
			q.push({ ny, nx });
		}
	}
	return cnt >= K;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> S[i][j];
	while (L + 1 < R)
	{
		int m = (L + R) / 2;
		if (solve(m)) R = m;
		else L = m;
	}
	cout << R << '\n';
}

// https://www.acmicpc.net/problem/15573