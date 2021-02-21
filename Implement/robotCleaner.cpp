#include <iostream>
#include <vector>
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
vector<vector<int>> area;
vector<vector<bool>> v;
int n, m, r, c, d;
int nextD(int idx)
{
	int r;
	switch (idx)
	{
	case 0:
		r = 3;
		break;
	case 1:
		r = 0;
		break;
	case 2:
		r = 1;
		break;
	default:
		r = 2;
	}
	return r;
}
int dfs()
{
	int next = nextD(d);
	while (true)
	{
		if (next == d)
		{
			if (!v[r + dy[next]][c + dx[next]] && area[r + dy[next]][c + dx[next]] == 0)
				break;
			int b = nextD(nextD(d));
			if (area[r + dy[b]][c + dx[b]] == 1)
				return 0;
			else
			{
				r += dy[b];
				c += dx[b];
				return dfs();
			}
		}
		if (v[r + dy[next]][c + dx[next]] || area[r + dy[next]][c + dx[next]] == 1)
			next = nextD(next);
		else
			break;
	}

	d = next;
	r += dy[d];
	c += dx[d];
	v[r][c] = true;
	return dfs() + 1;
}
int main()
{
	cin >> n >> m;
	area.resize(n, vector<int>(m));
	v.resize(n, vector<bool>(m, false));
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> area[i][j];
	v[r][c] = true;
	int ans = dfs() + 1;
	cout << ans << endl;
}

// https://www.acmicpc.net/problem/14503

/*
Just simulating problem
*/