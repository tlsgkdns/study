#include <iostream>
#include <vector>
using namespace std;

int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
vector<vector<bool>> room;
int R, C, k, br, bc, y, x;
int d[4];

bool inRange(int r, int c)
{
	return (r >= 0 && c >= 0 && r < R && c < C);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	room.resize(R, vector<bool>(C, false));
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> br >> bc;
		room[br][bc] = true;
	}
	cin >> y >> x;
	room[y][x] = true;
	for (int i = 0; i < 4; i++) cin >> d[i];
	int dir = 0, cnt = 0;
	while (true)
	{
		int ny = y + dy[d[dir]];
		int nx = x + dx[d[dir]];
		if (!inRange(ny, nx) || room[ny][nx])
		{
			cnt++;
			if (cnt == 4) break;
			dir = (dir + 1) % 4;
			continue;
		}
		else
			cnt = 0;
		y = ny; x = nx;
		room[y][x] = true;
	}
	cout << y << " " << x << '\n';
}

// https://www.acmicpc.net/problem/13901