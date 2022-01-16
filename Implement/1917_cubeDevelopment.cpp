#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int figure[6][6];
bool v[6][6], ss[6];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
pair<int, int> NON = { -1, -1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < 6 && x < 6;
}
bool anss[3];
enum Dir
{
	North, East, South, West
};
enum Side
{
	Down, Front, Right, Back, Left, Up
};

Side faces[4] = { Down, Front, Up, Back };
Side sides[4] = { Down, Left, Up, Right };

void rollEast()
{
	Side tmp[4];
	tmp[0] = sides[3];
	for (int i = 0; i < 3; i++)
		tmp[i + 1] = sides[i];
	faces[0] = tmp[0];
	faces[2] = tmp[2];
	for (int i = 0; i < 4; i++)
		sides[i] = tmp[i];
}
void rollWest()
{
	Side tmp[4];
	tmp[3] = sides[0];
	for (int i = 0; i < 3; i++)
		tmp[i] = sides[i + 1];
	faces[0] = tmp[0];
	faces[2] = tmp[2];
	for (int i = 0; i < 4; i++)
		sides[i] = tmp[i];
}
void rollSouth()
{
	Side tmp[4];
	tmp[3] = faces[0];
	for (int i = 0; i < 3; i++)
		tmp[i] = faces[i + 1];
	sides[0] = tmp[0];
	sides[2] = tmp[2];
	for (int i = 0; i < 4; i++)
		faces[i] = tmp[i];
}
void rollNorth()
{
	Side tmp[4];
	tmp[0] = faces[3];
	for (int i = 0; i < 3; i++)
		tmp[i + 1] = faces[i];
	sides[0] = tmp[0];
	sides[2] = tmp[2];
	for (int i = 0; i < 4; i++)
		faces[i] = tmp[i];
}
/*
0 0 0 0 0 0
0 0 1 0 0 0
0 1 1 1 1 0
0 0 1 0 0 0
0 0 0 0 0 0
*/

void dfs(int y, int x)
{
	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!inRange(ny, nx) || v[ny][nx] || figure[ny][nx] == 0) continue;
		v[ny][nx] = true;
		if (d == 0) rollNorth();
		else if (d == 1) rollEast();
		else if (d == 2) rollSouth();
		else if (d == 3) rollWest();
		ss[faces[0]] = true;
		dfs(ny, nx);
		if (d == 0) rollSouth();
		else if (d == 1) rollWest();
		else if (d == 2) rollNorth();
		else if (d == 3) rollEast();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int T = 0; T < 3; T++)
	{
		pair<int, int> spos = NON;
		vector<pair<int, int>> pos;
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
			{
				cin >> figure[i][j];
				if (figure[i][j] == 1 && spos.first == -1)
					spos = { i, j };
			}
		faces[0] = Down; faces[1] = Front;
		faces[2] = Up; faces[3] = Back;
		sides[0] = Down; sides[1] = Left;
		sides[2] = Up; sides[3] = Right;
		memset(v, false, sizeof(v));
		memset(ss, false, sizeof(ss));
		ss[faces[0]] = true;
		v[spos.first][spos.second] = true;
		dfs(spos.first, spos.second);
		bool a = true;
		dfs(spos.first, spos.second);
		for (int i = 0; i < 6; i++)
			if (!ss[i])
				a = false;
		anss[T] = a;
	}
	for (int t = 0; t < 3; t++)
	{
		if (anss[t]) cout << "yes\n";
		else cout << "no\n";
	}
}

// https://www.acmicpc.net/problem/1917