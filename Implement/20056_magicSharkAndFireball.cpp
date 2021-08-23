#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, K, R, C, MS, S, D;
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
struct fire
{
	int m, s, d;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	vector<vector<vector<fire>>> grid(N + 1, vector<vector<fire>>(N + 1));
	for (int i = 0; i < M; i++)
	{
		cin >> R >> C >> MS >> S >> D;
		grid[R][C].push_back({ MS, S, D });
	}

	for (int k = 0; k < K; k++)
	{
		vector<vector<vector<fire>>> tmp(N + 1, vector<vector<fire>>(N + 1));
		for (int y = 0; y < grid.size(); y++)
			for (int x = 0; x < grid[y].size(); x++)
				for (int i = 0; i < grid[y][x].size(); i++)
				{
					int ny = y + grid[y][x][i].s * dy[grid[y][x][i].d];
					int nx = x + grid[y][x][i].s * dx[grid[y][x][i].d];
					if (ny > N) ny = (ny % N); if (ny <= 0) ny = N - abs(ny) % N;
					if (nx > N) nx = (nx % N); if (nx <= 0) nx = N - abs(nx) % N;
					tmp[ny][nx].push_back({ grid[y][x][i] });
				}
		for (int y = 0; y < tmp.size(); y++)
			for (int x = 0; x < tmp[y].size(); x++)
			{
				if (tmp[y][x].size() <= 1) continue;
				int sm = 0, ss = 0, odd = (tmp[y][x][0].d % 2);
				bool dDiff = false;
				for (int i = 0; i < tmp[y][x].size(); i++)
				{
					sm += tmp[y][x][i].m;
					ss += tmp[y][x][i].s;
					if (tmp[y][x][i].d % 2 != odd) dDiff = true;
				}
				int avgm = sm / 5, avgs = ss / tmp[y][x].size(), avgd = dDiff;
				tmp[y][x] = vector<fire>();
				if (avgm == 0) continue;
				for (int i = 0; i < 4; i++)
					tmp[y][x].push_back({ avgm, avgs, avgd + (i * 2) });
			}
		grid = tmp;
	}
	int ans = 0;
	for (int y = 0; y < grid.size(); y++)
		for (int x = 0; x < grid[y].size(); x++)
			for (int z = 0; z < grid[y][x].size(); z++)
				ans += grid[y][x][z].m;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/20056