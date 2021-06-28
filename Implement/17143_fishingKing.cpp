#include <iostream>
#include <vector>
using namespace std;
using shark = pair<pair<int, bool>, pair<int, int>>;
const shark emptyP = make_pair(make_pair(0, false), make_pair(-1, -1));
vector<vector<shark>> fish;
int R, C, M, ans = 0;

int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0 ,1, -1 };
int getOpp(int d)
{
	int ret = -1;
	switch (d)
	{
	case 1:
		ret = 2;
		break;
	case 2:
		ret = 1;
		break;
	case 3:
		ret = 4;
		break;
	case 4:
		ret = 3;
		break;
	}
	return ret;
}
void movefish(shark sh, int h, int w, bool seq)
{
	int size = sh.first.first;
	int speed = sh.second.first;
	int dir = sh.second.second;
	int th = h, tw = w;
	if (!seq) fish[h][w] = emptyP;
	for (int k = 0; k < speed; k++)
	{
		th = th + dy[dir];
		tw = tw + dx[dir];
		if (th < 0 || tw < 0 || th >= R || tw >= C)
		{
			th -= dy[dir];
			tw -= dx[dir];
			dir = getOpp(dir);
			th += dy[dir];
			tw += dx[dir];
		}
	}
	if (fish[th][tw] != emptyP)
	{
		if (!fish[th][tw].first.second)
		{
			shark tmp = fish[th][tw];
			fish[th][tw] = make_pair(make_pair(size, true), make_pair(speed, dir));
			movefish(tmp, th, tw, true);
		}
		else if (size > fish[th][tw].first.first)
			fish[th][tw] = make_pair(make_pair(size, true), make_pair(speed, dir));
	}
	else
		fish[th][tw] = make_pair(make_pair(size, true), make_pair(speed, dir));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> M;
	fish.resize(R, vector<pair<pair<int, bool>, pair<int, int>>>(C, emptyP));
	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		if (d == 1 || d == 2) s %= (2 * (R - 1));
		else s = s % (2 * (C - 1));
		fish[r - 1][c - 1] = make_pair(make_pair(z, false), make_pair(s, d));
	}
	for (int i = 0; i < C; i++)
	{
		for (int h = 0; h < R; h++)
			for (int w = 0; w < C; w++)
				if (fish[h][w] != emptyP)
					fish[h][w].first.second = false;
		for (int j = 0; j < R; j++)
			if (fish[j][i] != emptyP)
			{
				ans += fish[j][i].first.first;
				fish[j][i] = emptyP;
				break;
			}
		for (int h = 0; h < R; h++)
			for (int w = 0; w < C; w++)
				if (fish[h][w] != emptyP && !fish[h][w].first.second)
					movefish(fish[h][w], h, w, false);
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/17143