#include <iostream>
#include <vector>
#include <algorithm>
#define NEWS 4
using namespace std;

int dx[6] = { -1, 1, 0, 0, 1, -1 };
int dy[6] = { 0, 0, -1, 1 , 0, 0 };
int n, m;
vector<pair<int, pair<int, int>>> camera;

int goDirection(vector<vector<int>>& cctv, int i, int j, int d)
{
	int ret = 0;

	while (i >= 0 && j >= 0 && i < n && j < m && cctv[i][j] != 6)
	{
		if (cctv[i][j] == 0)
		{
			ret++;
			cctv[i][j] = -1;
		}

		i += dx[d];
		j += dy[d];
	}

	return ret;
}
int cctvTwo(vector<vector<int>>& cctv, int i, int j, int d)
{
	return goDirection(cctv, i, j, d) + goDirection(cctv, i, j, d + 1);
}

int cctvThree(vector<vector<int>>& cctv, int i, int j, int d)
{
	return goDirection(cctv, i, j, d) + goDirection(cctv, i, j, (d + 2));
}

int cctvFour(vector<vector<int>>& cctv, int i, int j, int d)
{
	int one = goDirection(cctv, i, j, d);
	int two = goDirection(cctv, i, j, (d + 1) % NEWS);
	int three = goDirection(cctv, i, j, (d + 2) % NEWS);
	return one + two + three;
}

int cctvFive(vector<vector<int>>& cctv, int i, int j)
{
	int ret = 0;
	for (int d = 0; d < NEWS; d++)
		ret += goDirection(cctv, i, j, d);

	return ret;
}

int brute(vector<vector<int>> cctv, int index, int monitor)
{
	if (index == camera.size()) return monitor;
	int kind = camera[index].first;
	int i = camera[index].second.first;
	int j = camera[index].second.second;
	vector<vector<int>> extra(cctv);
	int mon, tmp, ret = 0;

	for (int d = 0; d < NEWS; d++)
	{
		switch (kind)
		{
		case 1:
			mon = goDirection(cctv, i, j, d);
			ret = max(ret, brute(cctv, index + 1, mon + monitor));
			break;
		case 2:
			if (d % 2 == 1) continue;
			mon = cctvTwo(cctv, i, j, d);
			ret = max(ret, brute(cctv, index + 1, mon + monitor));
			break;
		case 3:
			mon = cctvThree(cctv, i, j, d);
			ret = max(ret, brute(cctv, index + 1, mon + monitor));
			break;
		case 4:
			mon = cctvFour(cctv, i, j, d);
			tmp = brute(cctv, index + 1, mon + monitor);
			ret = max(ret, tmp);
			break;
		case 5:
			if (d != 0) continue;
			mon = cctvFive(cctv, i, j);
			ret = max(ret, brute(cctv, index + 1, mon + monitor));
			break;
		}
		cctv = extra;
	}

	return ret;
}
int main()
{
	int area;
	cin >> n >> m;
	area = 0;
	vector<vector<int>> cctv(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> cctv[i][j];
			if (cctv[i][j] != 0 && cctv[i][j] != 6)
				camera.push_back(make_pair(cctv[i][j], make_pair(i, j)));
			if (cctv[i][j] == 0)
				area++;
		}


	int ans = area - brute(cctv, 0, 0);

	cout << ans << endl;
}

/*
A little complicated bruteforce problem.
I hate bruteforce
*/