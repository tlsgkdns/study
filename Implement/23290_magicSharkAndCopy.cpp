#include <iostream>
#include <vector>
using namespace std;

int dy1[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dx1[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy2[4] = { -1, 0, 1, 0 };
int dx2[4] = { 0, -1, 0, 1 };

vector<vector<vector<int>>> grid(4, vector<vector<int>>(4)), copied;
vector<vector<int>> smell(4, vector<int>(4, 0));
vector<int> route;  pair<int, int> shark;
vector<vector<bool>> v;
int maxCatched, M, S, fx, fy, dir, ans = 0;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < 4 && x < 4;
}
void getRidOfSmell()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (smell[i][j] > 0)
				smell[i][j]--;
}
int getNextDir(int dir)
{
	if (dir == 1) return 8;
	else return dir - 1;
}
void copyFish()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < grid[i][j].size(); k++)
				copied[i][j].push_back(grid[i][j][k]);
}
void pasteFish()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < copied[i][j].size(); k++)
			{
				grid[i][j].push_back(copied[i][j][k]);
				ans++;
			}
}
void moveFish()
{
	vector<vector<vector<int>>> tmp(4, vector<vector<int>>(4, vector<int>()));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < grid[i][j].size(); k++)
			{
				smell;
				int d = grid[i][j][k];
				int ny = i + dy1[d];
				int nx = j + dx1[d];
				int startDir = d;
				bool cantMove = false;
				while (!inRange(ny, nx) || smell[ny][nx] > 0 || shark == make_pair(ny, nx))
				{
					d = getNextDir(d);
					if (d == startDir)
					{
						cantMove = true;
						break;
					}
					ny = i + dy1[d];
					nx = j + dx1[d];
				}
				if (cantMove)
					tmp[i][j].push_back(d);
				else
					tmp[ny][nx].push_back(d);
			}
	grid = tmp;
	shark; smell;
}

void searchRoute(int y, int x, vector<int> _route, int catched)
{
	if (_route.size() == 3)
	{
		if (maxCatched < catched)
		{
			route = _route;
			maxCatched = catched;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy2[i];
		int nx = x + dx2[i];
		if (!inRange(ny, nx)) continue;
		_route.push_back(i);
		if (!v[ny][nx])
		{
			v[ny][nx] = true;
			searchRoute(ny, nx, _route, catched + (int)grid[ny][nx].size());
			v[ny][nx] = false;
		}
		else
			searchRoute(ny, nx, _route, catched);
		_route.pop_back();
	}
}
void moveShark()
{
	for (int i = 0; i < route.size(); i++)
	{
		shark.first += dy2[route[i]];
		shark.second += dx2[route[i]];
		if (!grid[shark.first][shark.second].empty())
		{
			ans -= (int)grid[shark.first][shark.second].size();
			grid[shark.first][shark.second] = vector<int>();
			smell[shark.first][shark.second] = 3;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> S;
	for (int i = 0; i < M; i++)
	{
		cin >> fx >> fy >> dir;
		grid[fx - 1][fy - 1].push_back(dir);
		ans++;
	}
	cin >> shark.first >> shark.second; shark.first--; shark.second--;
	vector<int> r;
	for (int s = 0; s < S; s++)
	{
		copied = vector<vector<vector<int>>>(4, vector<vector<int>>(4));
		r = vector<int>(); maxCatched = -1;
		copyFish(); moveFish();
		v = vector<vector<bool>>(4, vector<bool>(4, false));
		searchRoute(shark.first, shark.second, r, 0);
		moveShark(); getRidOfSmell(); pasteFish();
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/23290