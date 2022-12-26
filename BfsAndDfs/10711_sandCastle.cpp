#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
int H, W, ans = 0;
char ch;
int S[1001][1001], v[1001][1001];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
queue<pii> q;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < H&& x < W;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> H >> W;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			cin >> ch;
			if (ch == '.')
			{
				S[i][j] = 0;
				v[i][j] = 0;
				q.push({ i, j });
			}
			else S[i][j] = (ch - '0');
		}

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || v[ny][nx] >= 0) continue;
			if (S[ny][nx] == 0)
			{
				v[ny][nx] = v[y][x];
				q.push({ ny, nx });
			}
			else if (--S[ny][nx] == 0)
			{
				v[ny][nx] = v[y][x] + 1;
				ans = max(v[ny][nx], ans);
				q.push({ ny, nx });
			}
		}
	}

	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10711