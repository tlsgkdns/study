#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<vector<int>> lab;
vector<int> vPos;
int n, m, safe = 0, ans = -1;
int ptoi(int a1, int a2) { return a1 * m + a2; }
void spread(vector<vector<int>> l)
{
	int s = safe;
	queue<int> q;
	for (int p : vPos) q.push(p);
	while (!q.empty())
	{
		int y = q.front() / m;
		int x = q.front() % m;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (ny < 0 || nx < 0 || ny == n || nx == m
				|| l[ny][nx] != 0) continue;
			l[ny][nx] = 2;
			s--;
			q.push(ptoi(ny, nx));
		}
	}
	if (s > ans)
		ans = s;
}

void wall(vector<vector<int>> l, int w)
{
	if (w == 3)
	{
		spread(l);
		return;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (l[i][j] == 0)
			{
				l[i][j] = 1;
				wall(l, w + 1);
				l[i][j] = 0;
			}
		}
}
int main()
{
	cin >> n >> m;
	lab.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> lab[i][j];
			if (lab[i][j] == 2)	vPos.push_back(ptoi(i, j));
			if (lab[i][j] == 0) safe++;
		}
	safe -= 3;
	wall(lab, 0);
	cout << ans << endl;
}

// https://www.acmicpc.net/problem/14502