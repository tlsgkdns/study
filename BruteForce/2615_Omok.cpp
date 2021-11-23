#include <iostream>
#include <cstring>
using namespace std;

int board[20][20];
bool v[20][20][8];
int dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dx[8] = { 1, 0, -1, -1, 1, 0, -1, 1 };

bool inRange(int y, int x)
{
	return y > 0 && x > 0 && y < 20 && x < 20;
}
int brute(int y, int x, int d)
{
	int ny = y + dy[d];
	int nx = x + dx[d];
	if (!inRange(ny, nx) || board[y][x] != board[ny][nx] || v[ny][nx][d]) return 0;
	v[ny][nx][d] = true;
	return brute(ny, nx, d) + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j < 20; j++)
			cin >> board[i][j];
	int ansY = -1, ansX = -1;
	for (int j = 1; j < 20; j++)
	{
		for (int i = 1; i < 20; i++)
		{
			if (board[i][j] == 0) continue;
			for (int d = 0; d < 8; d++)
			{
				if (brute(i, j, d) + 1 == 5)
				{
					ansY = i; ansX = j;
					break;
				}
			}
			if (ansY != -1) break;
		}
		if (ansY != -1) break;
	}
	if (ansY == -1) cout << 0 << '\n';
	else
	{
		cout << board[ansY][ansX] << '\n';
		cout << ansY << " " << ansX << '\n';
	}
}
// https://www.acmicpc.net/problem/2615