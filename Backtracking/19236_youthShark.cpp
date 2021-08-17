#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
using pos = pair<int, int>;
using Shark = pair<pair<int, int>, pair<int, int>>;
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int nb, dr;
bool isPosValid(int y, int x)
{
	return (y >= 0 && x >= 0 && y < 4 && x < 4);
}
class Fish
{
private:
	int num;
	int dir;
public:
	Fish(int n, int d)
	{
		num = n;
		dir = d;
	}
	Fish(const Fish& f)
	{
		num = f.num;
		dir = f.dir;
	}
	void setNextDir()
	{
		dir = (dir % 8) + 1;
	}
	bool isEaten()
	{
		return (num <= 0 && dir <= 0);
	}
	int getNum()
	{
		return num;
	}
	int getDir()
	{
		return dir;
	}
};

class Sea
{
public:
	vector<vector<Fish*>> fishes;
	Shark shark;
	Sea(const Sea& s)
	{
		fishes.resize(4, vector<Fish*>(4));
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				fishes[i][j] = new Fish(s.fishes[i][j]->getNum(), s.fishes[i][j]->getDir());
		shark = s.shark;
	}
	Sea()
	{
		fishes.resize(4, vector<Fish*>(4));
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				cin >> nb >> dr;
				fishes[i][j] = new Fish(nb, dr);
			}
		shark = make_pair(make_pair(0, 0), make_pair(fishes[0][0]->getNum(), fishes[0][0]->getDir()));
		fishes[0][0] = new Fish(-1, -1);
	}
	bool isSharkInPos(int y, int x)
	{
		return (shark.first.first == y && shark.first.second == x);
	}
	bool canFishMove(int y, int x)
	{
		return (isPosValid(y, x) && !isSharkInPos(y, x));
	}
	void swapFishPos(pos p1, pos p2)
	{
		swap(fishes[p1.first][p1.second], fishes[p2.first][p2.second]);
	}
	void moveFish()
	{
		for (int n = 1; n <= 16; n++)
		{
			int y = -1, x = -1;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (fishes[i][j]->getNum() == n)
					{
						y = i; x = j;
					}
			if (y < 0) continue;
			int ny = y + dy[fishes[y][x]->getDir()];
			int nx = x + dx[fishes[y][x]->getDir()];
			int cnt = 0;
			while (!canFishMove(ny, nx))
			{
				if (cnt > 8) break;
				fishes[y][x]->setNextDir();
				ny = y + dy[fishes[y][x]->getDir()];
				nx = x + dx[fishes[y][x]->getDir()];
				cnt++;
			}
			if (cnt > 8) continue;
			swapFishPos(make_pair(y, x), make_pair(ny, nx));
		}
	}
	bool sharkAteFish(int dist)
	{
		int ny = shark.first.first + dist * dy[shark.second.second];
		int nx = shark.first.second + dist * dx[shark.second.second];
		if (!isPosValid(ny, nx) || fishes[ny][nx]->isEaten()) return false;
		shark.first = make_pair(ny, nx);
		shark.second.first += fishes[ny][nx]->getNum();
		shark.second.second = fishes[ny][nx]->getDir();
		fishes[ny][nx] = new Fish(-1, -1);
		return true;
	}
	int getEatenFish()
	{
		return shark.second.first;
	}
};

int dfs(Sea s)
{
	s.moveFish();
	Sea tmp(s);
	int rt = tmp.getEatenFish();
	int ret = s.getEatenFish();
	for (int ds = 1; ds <= 3; ds++)
	{
		if (!s.sharkAteFish(ds)) continue;
		ret = max(ret, dfs(s));
		s = tmp;
	}
	return ret;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	Sea* sea = new Sea();
	int ans = dfs(*sea);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/19236