#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int L;
string str;
char maze[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(maze, '#', sizeof(maze));
	cin >> L; cin >> str;
	int rx1 = 50, ry1 = 50, rx2 = 50, ry2 = 50;
	int y = 50, x = 50, d = 0;
	maze[y][x] = '.';
	for (int l = 0; l < L; l++)
	{
		switch (str[l])
		{
		case 'R':
			d = (d + 1) % 4;
			break;
		case 'L':
			if (d == 0) d = 3;
			else d--;
			break;
		case 'F':
			y = y + dy[d];
			x = x + dx[d];
			ry1 = min(y, ry1); ry2 = max(y, ry2);
			rx1 = min(x, rx1); rx2 = max(x, rx2);
			maze[y][x] = '.';
			break;
		}
	}
	for (int i = ry1; i <= ry2; i++)
	{
		for (int j = rx1; j <= rx2; j++)
			cout << maze[i][j];
		cout << '\n';
	}
}
// https://www.acmicpc.net/problem/1347