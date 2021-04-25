#include <iostream>
#include <vector>
using namespace std;
using space = vector<vector<int>>;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<vector<int>> operator+(vector<vector<int>>& h1, vector<vector<int>>& h2)
{
	int r = h1.size(), c = h1[0].size();
	vector<vector<int>> ret(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			ret[i][j] = h1[i][j] + h2[i][j];
	return ret;
}
struct fineDust
{
	vector<vector<int>> house;
	int row = 0, column = 0, sum = 0, cleaner = 0;
	fineDust(int r, int c)
	{
		row = r; column = c;
		house.resize(r, vector<int>(c));
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				cin >> house[i][j];
				if (house[i][j] > 0)
					sum += house[i][j];
				if (house[i][j] == -1) cleaner = i;

			}
	}
	void spread()
	{
		vector<vector<int>> newHouse(row, vector<int>(column, 0));
		for (int r = 0; r < row; r++)
			for (int c = 0; c < column; c++)
			{
				if (house[r][c] > 0)
				{
					int sp = (house[r][c] / 5);
					for (int i = 0; i < 4; i++)
					{
						int nr = dy[i] + r;
						int nc = dx[i] + c;
						if (nr < 0 || nc < 0 || nr == row || nc == column || house[nr][nc] == -1) continue;
						newHouse[nr][nc] += sp;
						house[r][c] -= sp;
					}
				}
			}
		house = newHouse + house;
	}
	void airCleanAbove()
	{
		int idx = 0;
		pair<int, int> start = { cleaner - 1, 0 };
		pair<int, int> pos = start;
		vector<vector<int>> newHouse(cleaner, vector<int>(column, 0));
		for (int i = 1; i < cleaner - 1; i++)
			for (int j = 1; j < column - 1; j++)
				newHouse[i][j] = house[i][j];
		newHouse[cleaner - 1][0] = -1;
		while (idx != 3 || pos != start)
		{
			int nr = dy[idx] + pos.first;
			int nc = dx[idx] + pos.second;
			if (nr < 0 || nc < 0 || nr == cleaner || nc == column)
			{
				idx++;
				continue;
			}
			if (house[nr][nc] == -1)
			{
				sum -= house[pos.first][pos.second];
				break;
			}
			if (house[pos.first][pos.second] > 0)
			{
				newHouse[nr][nc] = house[pos.first][pos.second];
			}
			pos = make_pair(nr, nc);
		}
		for (int i = 0; i < cleaner; i++)
			for (int j = 0; j < column; j++)
				house[i][j] = newHouse[i][j];
	}
	void airCleanBelow()
	{
		int idx = 0;
		pair<int, int> start = { cleaner, 0 };
		pair<int, int> pos = start;
		vector<vector<int>> newHouse(row, vector<int>(column, 0));
		for (int i = cleaner + 1; i < row - 1; i++)
			for (int j = 1; j < column - 1; j++)
				newHouse[i][j] = house[i][j];
		newHouse[cleaner][0] = -1;
		while (idx != 3 || pos != start)
		{
			int nr = -dy[idx] + pos.first;
			int nc = dx[idx] + pos.second;
			if (nr == row || nc < 0 || nr < cleaner || nc == column)
			{
				idx++;
				continue;
			}
			if (house[nr][nc] == -1)
			{
				sum -= house[pos.first][pos.second];
				break;
			}
			if (house[pos.first][pos.second] > 0)
			{
				newHouse[nr][nc] = house[pos.first][pos.second];
			}

			pos = make_pair(nr, nc);
		}
		for (int i = cleaner; i < row; i++)
			for (int j = 0; j < column; j++)
				house[i][j] = newHouse[i][j];
	}
	void airCleaning(int t)
	{
		for (int i = 0; i < t; i++)
		{
			spread();
			airCleanAbove();
			airCleanBelow();
		}
	}
};
int r, c, t;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c >> t;
	fineDust fd(r, c);
	fd.airCleaning(t);
	cout << fd.sum << '\n';
}

// https://www.acmicpc.net/problem/17144