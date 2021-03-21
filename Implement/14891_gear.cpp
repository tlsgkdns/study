#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<bool>> gears(4, vector<bool>(8));
int k;
void rotateClock(vector<bool>& g)
{
	vector<bool> tmp(8);
	tmp[0] = g[7];
	for (int i = 1; i < 8; i++)
		tmp[i] = g[i - 1];
	g = tmp;
}
void rotateAntiClock(vector<bool>& g)
{
	vector<bool> tmp(8);
	tmp[7] = g[0];
	for (int i = 0; i < 7; i++)
		tmp[i] = g[i + 1];
	g = tmp;
}
int main()
{
	for (int i = 0; i < 4; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++)
		{
			if (s[j] == '1')
				gears[i][j] = true;
			else
				gears[i][j] = false;
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int n, d;
		cin >> n >> d;
		bool c = (d == -1) ? false : true;
		vector<pair<int, bool>> r;
		r.push_back({ n - 1, c });
		for (int a = n - 1; a >= 1; a--)
		{
			if (gears[a - 1][2] != gears[a][6])
			{
				r.push_back({ a - 1, !c });
				c = !c;
			}
			else break;
		}
		c = (d == -1) ? false : true;
		for (int a = n - 1; a < 3; a++)
		{
			if (gears[a + 1][6] != gears[a][2])
			{
				r.push_back({ a + 1, !c });
				c = !c;
			}
			else break;
		}
		for (pair<int, bool> p : r)
		{
			if (p.second) rotateClock(gears[p.first]);
			else rotateAntiClock(gears[p.first]);
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		if (gears[i][0])
			ans += pow(2, i);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14891

/*
little complicated than I expected But not that difficult.
*/