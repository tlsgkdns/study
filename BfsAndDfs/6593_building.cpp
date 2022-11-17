#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int L, R, C, Sz, Sy, Sx, Ez, Ey, Ex;
int dz[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dx[6] = { 0, 0, 0, 0, -1, 1 };
bool B[31][31][31];
int v[31][31][31];
char ch;
bool inRange(int z, int y, int x)
{
	return z >= 0 && z < L&& y >= 0 && y < R&& x >= 0 && x < C;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		memset(B, false, sizeof(B)); memset(v, -1, sizeof(v));
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 0; i < L; i++)
			for (int j = 0; j < R; j++)
				for (int k = 0; k < C; k++)
				{
					cin >> ch;
					if (ch == 'E')
					{
						Ez = i; Ey = j; Ex = k;
					}
					else if (ch == 'S')
					{
						Sz = i; Sy = j; Sx = k;
					}
					else if (ch == '#')
					{
						B[i][j][k] = true;
					}
				}
		v[Sz][Sy][Sx] = 0;
		queue<pair<pair<int, int>, int>> q;
		q.push({ {Sz, Sy}, Sx });
		int ans = -1;
		while (!q.empty())
		{
			int z = q.front().first.first;
			int y = q.front().first.second;
			int x = q.front().second;
			q.pop();
			if (Ez == z && Ey == y && Ex == x)
			{
				ans = v[z][y][x];
				break;
			}
			for (int d = 0; d < 6; d++)
			{
				int nz = z + dz[d];
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (!inRange(nz, ny, nx) || v[nz][ny][nx] >= 0 || B[nz][ny][nx]) continue;
				v[nz][ny][nx] = v[z][y][x] + 1;
				q.push({ {nz, ny}, nx });
			}
		}
		if (ans < 0) cout << "Trapped!\n";
		else cout << "Escaped in " << ans << " minute(s).\n";
	}

}

// https://www.acmicpc.net/problem/6593