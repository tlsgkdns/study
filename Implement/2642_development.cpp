#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;
int plane[6][6];
pii spoint;
int faces[4] = { 0, 0, 0, 0 };
int sides[4] = { 0, 0, 0, 0 };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool v[7] = { false, false, false, false, false, false, false };
void rollEast()
{
	int tmp[4];
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
	int tmp[4];
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
	int tmp[4];
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
	int tmp[4];
	tmp[0] = faces[3];
	for (int i = 0; i < 3; i++)
		tmp[i + 1] = faces[i];
	sides[0] = tmp[0];
	sides[2] = tmp[2];
	for (int i = 0; i < 4; i++)
		faces[i] = tmp[i];
}
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < 6 && x < 6;
}
void dfs(int y, int x)
{
	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!inRange(ny, nx) || v[plane[ny][nx]] || plane[ny][nx] == 0) continue;
		v[plane[ny][nx]] = true;
		if (d == 0) rollNorth();
		else if (d == 1) rollEast();
		else if (d == 2) rollSouth();
		else if (d == 3) rollWest();
		faces[0] = plane[ny][nx]; sides[0] = plane[ny][nx];
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
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
		{
			cin >> plane[i][j];
			if (plane[i][j] == 1)
				spoint = { i, j };
		}
	v[1] = true; faces[0] = sides[0] = 1;
	dfs(spoint.first, spoint.second);
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		if (faces[i] == 0 || sides[i] == 0)
		{
			ans = 0;
			break;
		}
		if (i <= 1)
		{
			if (faces[i] == 1) ans = faces[i + 2];
			if (sides[i] == 1) ans = sides[i + 2];
		}
		if (i >= 2)
		{
			if (faces[i] == 1) ans = faces[i - 2];
			if (sides[i] == 1) ans = sides[i - 2];
		}
	}
	cout << ans << '\n';
}

//https://www.acmicpc.net/problem/2642