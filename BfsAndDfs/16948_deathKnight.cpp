#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, R1, R2, C1, C2, v[201][201], ans = -1;
int dy[6] = { -2, -2, 0, 0, 2, 2 };
int dx[6] = { -1, 1, -2, 2, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N&& x < N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> R1 >> C1 >> R2 >> C2;
	queue<pair<int, int>> q;
	q.push({ R1, C1 });
	memset(v, -1, sizeof(v));
	v[R1][C1] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == R2 && x == C2)
		{
			ans = v[y][x];
			break;
		}
		for (int d = 0; d < 6; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || v[ny][nx] >= 0) continue;
			v[ny][nx] = v[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16948