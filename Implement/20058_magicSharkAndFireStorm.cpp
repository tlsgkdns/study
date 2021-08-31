#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> ice, tmp1;
vector<vector<bool>> v;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int N, Q, L, s = 0;
void storm(int x1, int y1, int x2, int y2)
{
	int d = 0;
	while (x2 - d >= x1 + d)
	{
		int nx1 = x1 + d, nx2 = x2 - d, ny1 = y1 + d, ny2 = y2 - d;
		for (int c = nx1; c < nx2; c++)
			tmp1[(c - nx1) + ny1][nx2] = ice[ny1][c];
		for (int r = ny1; r < ny2; r++)
			tmp1[ny2][nx2 - (r - ny1)] = ice[r][nx2];
		for (int c = nx2; c > nx1; c--)
			tmp1[(c - nx2) + ny2][nx1] = ice[ny2][c];
		for (int r = ny2; r > ny1; r--)
			tmp1[ny1][nx1 + ((ny2 - ny1) - (r - ny1))] = ice[r][nx1];
		d++;
	}
	ice = tmp1;
}
bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < N && x < N);
}
int dfs(int y, int x)
{
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!inRange(ny, nx) || v[ny][nx] || ice[ny][nx] == 0) continue;
		v[ny][nx] = true;
		ret += dfs(ny, nx);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	N = pow(2, N);
	ice.resize(N, vector<int>(N));
	v.resize(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> ice[i][j];
			s += ice[i][j];
		}
	for (int q = 0; q < Q; q++)
	{
		cin >> L;
		tmp1 = ice;
		int step = pow(2, L);
		for (int i = 0; i < N; i += step)
			for (int j = 0; j < N; j += step)
				storm(i, j, i + step - 1, j + step - 1);
		vector<pair<int, int>> melt;
		vector<vector<int>> tmp2(ice);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (ice[i][j] == 0) continue;
				int adj = 0;
				for (int d = 0; d < 4; d++)
				{
					int ny = dy[d] + i;
					int nx = dx[d] + j;
					if (ny < 0 || nx < 0 || ny >= N || nx >= N || ice[ny][nx] == 0) continue;
					adj++;
				}
				if (adj < 3)
				{
					tmp2[i][j]--;
					s--;
				}
			}
		ice = tmp2;
	}
	int blk = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (v[i][j] || ice[i][j] == 0) continue;
			v[i][j] = true;
			blk = max(blk, dfs(i, j));
		}
	cout << s << '\n';
	cout << blk << '\n';
}

// https://www.acmicpc.net/problem/20058