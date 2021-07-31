#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dy1[4] = { 0, 0, -1, 1 };
int dx1[4] = { 1, -1, 0, 0 };
int dy2[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dx2[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };
int K, W, H, g;
bool isInside(int y, int x)
{
	return ((y >= 0) && (x >= 0) && (y < H) && (x < W));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K;
	cin >> W >> H;
	vector<vector<bool>> grid(H, vector<bool>(W));
	vector<vector<vector<bool>>>v(H, vector<vector<bool>>(W, vector<bool>(K + 1, false)));

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			cin >> g;
			grid[i][j] = g;
		}
	v[0][0][K] = true;
	int ans = -1;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(K, 0)));
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int k = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (y == H - 1 && x == W - 1)
		{
			ans = cnt;
			break;
		}
		if (k > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int ny = dy2[i] + y;
				int nx = dx2[i] + x;
				if (!isInside(ny, nx) || v[ny][nx][k - 1] || grid[ny][nx]) continue;
				v[ny][nx][k - 1] = true;
				q.push(make_pair(make_pair(ny, nx), make_pair(k - 1, cnt + 1)));
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = dy1[i] + y;
			int nx = dx1[i] + x;
			if (!isInside(ny, nx) || v[ny][nx][k] || grid[ny][nx]) continue;
			v[ny][nx][k] = true;
			q.push(make_pair(make_pair(ny, nx), make_pair(k, cnt + 1)));
		}
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1600