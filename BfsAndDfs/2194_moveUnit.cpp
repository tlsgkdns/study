#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, A, B, K, SY, SX, DY, DX, Y, X;
bool G[502][502];
int v[502][502], ans = -1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M >> A >> B >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> Y >> X;
		G[Y][X] = true;
	}
	cin >> SY >> SX >> DY >> DX;
	v[SY][SX] = 0;
	queue<pair<int, int>> q;
	q.push({ SY, SX });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == DY && x == DX)
		{
			ans = v[y][x];
			break;
		}
		if (y > 1 && v[y - 1][x] < 0)
		{
			bool br = false;
			for (int i = 0; i < B; i++)
				if (G[y - 1][x + i])
				{
					br = true;
					break;
				}
			if (!br)
			{
				v[y - 1][x] = v[y][x] + 1;
				q.push({ y - 1, x });
			}
		}
		if (y + A - 1 < N && v[y + 1][x] < 0)
		{
			bool br = false;
			for (int i = 0; i < B; i++)
				if (G[y + A][x + i])
				{
					br = true;
					break;
				}
			if (!br)
			{
				v[y + 1][x] = v[y][x] + 1;
				q.push({ y + 1, x });
			}
		}
		if (x > 1 && v[y][x - 1] < 0)
		{
			bool br = false;
			for (int i = 0; i < A; i++)
				if (G[y + i][x - 1])
				{
					br = true;
					break;
				}
			if (!br)
			{
				v[y][x - 1] = v[y][x] + 1;
				q.push({ y, x - 1 });
			}
		}
		if (x + B - 1 < M && v[y][x + 1] < 0)
		{
			bool br = false;
			for (int i = 0; i < A; i++)
				if (G[y + i][x + B])
				{
					br = true;
					break;
				}
			if (!br)
			{
				v[y][x + 1] = v[y][x] + 1;
				q.push({ y, x + 1 });
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2194
