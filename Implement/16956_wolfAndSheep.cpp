#include <iostream>

using namespace std;

char M[501][501];
int R, C;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < R && x < C;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> M[i][j];
	bool z = false;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (z) break;
			if (M[i][j] != 'W') continue;
			for (int d = 0; d < 4; d++)
			{
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (!inRange(ny, nx)) continue;
				if (M[ny][nx] == 'S')
				{
					z = true;
					break;
				}
			}
		}
	if (z) cout << 0 << '\n';
	else
	{
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
			{
				if (M[i][j] != 'S') continue;
				for (int d = 0; d < 4; d++)
				{
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (!inRange(ny, nx) || M[ny][nx] != '.') continue;
					M[ny][nx] = 'D';
				}
			}
		cout << 1 << '\n';
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
				cout << M[i][j];
			cout << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/16956