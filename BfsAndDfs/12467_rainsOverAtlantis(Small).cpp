#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int T, H, W, M;
int land[12][12], water[12][12], tmp[12][12];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool v[12][12];
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y <= H + 1 && x <= W + 1;
}
void bfs(int h)
{
	memset(v, false, sizeof(v));
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	v[0][0] = true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || v[ny][nx] || land[ny][nx] + water[ny][nx] >= h) continue;
			v[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> ans;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> H >> W >> M;
		memset(land, 0, sizeof(land));
		int mh = 0, s = 0;
		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++)
			{
				cin >> land[i][j];
				mh = max(mh, land[i][j]);
				s += land[i][j];
			}
		int day = 0;
		while (s > 0)
		{
			memset(water, 0, sizeof(water));
			memset(tmp, 0, sizeof(tmp));
			for (int h = 1; h <= mh; h++)
			{
				bfs(h);
				for (int i = 1; i <= H; i++)
					for (int j = 1; j <= W; j++)
						if (!v[i][j] && land[i][j] + water[i][j] < h)
							water[i][j]++;
			}

			for (int i = 1; i <= H; i++)
				for (int j = 1; j <= W; j++)
				{
					if (land[i][j] == 0) continue;
					int erode = mh;
					int lv = land[i][j] + water[i][j];
					for (int d = 0; d < 4; d++)
					{
						int ny = i + dy[d];
						int nx = j + dx[d];
						if (lv < land[ny][nx] + water[ny][nx]) continue;
						erode = min(land[ny][nx] + water[ny][nx], erode);
					}
					erode = min(abs(erode - lv), M);
					tmp[i][j] -= min(erode, land[i][j]);
				}
			for (int i = 1; i <= H; i++)
				for (int j = 1; j <= W; j++)
				{
					land[i][j] += tmp[i][j];
					s += tmp[i][j];
				}
			day++;

		}
		ans.push_back(day);
	}
	for (int i = 0; i < T; i++)
		cout << "Case #" << i + 1 << ": " << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/12467