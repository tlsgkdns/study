#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;
const int INF = 1000000001;
vector<int> order, used(5, false);
int origin[5][5][5], cube[5][5][5], v[5][5][5], ans = INF;
int dz[6] = { -1, 0, 0, 0, 0, 1 };
int dy[6] = { 0, -1, 1, 0, 0, 0 };
int dx[6] = { 0, 0, 0, -1, 1, 0 };

bool inRange(int z, int y, int x)
{
	return z >= 0 && z < 5 && y >= 0 && y < 5 && x >= 0 && x < 5;
}
void rotate(int idx)
{
	int tmp[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			tmp[i][j] = cube[idx][4 - j][i];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cube[idx][i][j] = tmp[i][j];
}

int bfs()
{
	memset(v, -1, sizeof(v));
	queue<tuple<int, int, int>> q;
	if (!cube[0][0][0]) return INF;
	q.push({ 0, 0, 0 });
	v[0][0][0] = 0;
	while (!q.empty())
	{
		int z = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		q.pop();
		if (z == 4 && y == 4 && x == 4)
			return v[z][y][x];
		for (int d = 0; d < 6; d++)
		{
			int nz = z + dz[d];
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(nz, ny, nx) || v[nz][ny][nx] != -1 || !cube[nz][ny][nx]) continue;
			v[nz][ny][nx] = v[z][y][x] + 1;
			q.push({ nz, ny, nx });
		}
	}
	return INF;
}

void solve()
{
	if ((int)order.size() == 5)
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)
					cube[order[i]][j][k] = origin[i][j][k];
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					for (int l = 0; l < 4; l++)
					{
						for (int m = 0; m < 4; m++)
						{

							ans = min(ans, bfs());
							rotate(4);
						}
						rotate(3);
					}
					rotate(2);
				}
				rotate(1);
			}
			rotate(0);
		}
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		if (used[i]) continue;
		used[i] = true;
		order.push_back(i);
		solve();
		order.pop_back();
		used[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> origin[i][j][k];
	solve();
	if (ans == INF) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16985