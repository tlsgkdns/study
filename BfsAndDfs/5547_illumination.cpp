#include <iostream>
#include <queue>

using namespace std;

bool v[102][102];
int ans = 0, W, H, B[102][102];
queue<pair<int, int>> q;
int dy[2][6] = { { -1, 1, 0, 0, -1, 1 }, {-1, 1, 0, 0, 1, -1} };
int dx[2][6] = { { 0, 0, -1, 1, -1, -1 }, {0, 0, -1, 1, 1, 1} };

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y <= H + 1 && x <= W + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> W >> H;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			cin >> B[i][j];
	q.push({ 0, 0 });
	v[0][0] = true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int ny = dy[y % 2][i] + y;
			int nx = dx[y % 2][i] + x;
			if (!inRange(ny, nx) || v[ny][nx]) continue;
			if (B[ny][nx])
			{
				++ans;
				continue;
			}
			v[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5547