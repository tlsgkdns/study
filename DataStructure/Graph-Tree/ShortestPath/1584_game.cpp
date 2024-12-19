#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

deque<pair<int, int>> dq;
int N, M, X1, Y1, X2, Y2;
int G[501][501], v[501][501];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y <= 500 && x <= 500;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X1 >> Y1 >> X2 >> Y2;
		if (X1 > X2) swap(X1, X2);
		if (Y1 > Y2) swap(Y1, Y2);
		for (int y = Y1; y <= Y2; y++)
			for (int x = X1; x <= X2; x++)
				G[y][x] = 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> X1 >> Y1 >> X2 >> Y2;
		if (X1 > X2) swap(X1, X2);
		if (Y1 > Y2) swap(Y1, Y2);
		for (int y = Y1; y <= Y2; y++)
			for (int x = X1; x <= X2; x++)
				G[y][x] = 2;
	}
	dq.push_back({ 0, 0 });
	v[0][0] = 0;
	while (!dq.empty())
	{
		int y = dq.front().first;
		int x = dq.front().second;
		dq.pop_front();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || G[ny][nx] == 2 || v[ny][nx] >= 0) continue;
			if (G[ny][nx] == 1)
			{
				v[ny][nx] = v[y][x] + 1;
				dq.push_back({ ny, nx });
			}
			else
			{
				v[ny][nx] = v[y][x];
				dq.push_front({ ny, nx });
			}
		}
	}
	cout << v[500][500] << '\n';
}

// https://www.acmicpc.net/problem/1584