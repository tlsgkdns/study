#include <iostream>
#include <vector>

using namespace std;

int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, 1, -1, -1, 0, 1 };

bool inRange(int R, int C, int y, int x)
{
	return (y >= 0 && x >= 0 && y < R && x < C);
}
void dfs(vector<vector<bool>>& v, vector<vector<bool>>& island,
	int y, int x)
{
	for (int i = 0; i < 8; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (!inRange(island.size(), island[0].size(), ny, nx)
			|| v[ny][nx] || !island[ny][nx]) continue;
		v[ny][nx] = true;
		dfs(v, island, ny, nx);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> ans;
	int w = -1, h = -1, is;
	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		int n = 0;
		vector<vector<bool>> island(h, vector<bool>(w)), v(h, vector<bool>(w, false));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				cin >> is;
				island[i][j] = is;
			}
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (!v[i][j] && island[i][j])
				{
					n++;
					dfs(v, island, i, j);
				}
		ans.push_back(n);
	}
	for (int a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/4963