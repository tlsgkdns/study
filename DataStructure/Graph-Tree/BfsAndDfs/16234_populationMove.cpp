#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
using ll = long long;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, l, r, s = 0, ans = 0;
vector<vector<int>> land;
vector<vector<bool>> v;
stack<pair<int, int>> st;
bool f = false;
void dfs(int y, int x)
{
	s += land[y][x];
	st.push({ y, x });
	for (int i = 0; i < 4; i++)
	{
		int ny = dx[i] + y;
		int nx = dy[i] + x;
		if (ny >= n || nx >= n || nx < 0 || ny < 0 || v[ny][nx]) continue;
		int sub = abs(land[y][x] - land[ny][nx]);
		if (sub >= l && sub <= r)
		{
			v[ny][nx] = true;
			f = true;
			dfs(ny, nx);
		}
	}
}
int main()
{
	cin >> n >> l >> r;
	land.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> land[i][j];

	while (true)
	{
		v = vector<vector<bool>>(n, vector<bool>(n, false));
		f = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (v[i][j]) continue;
				v[i][j] = true;
				s = 0;
				dfs(i, j);
				int pp = s / st.size();
				while (!st.empty())
				{
					land[st.top().first][st.top().second] = pp;
					st.pop();
				}
			}
		land;
		if (!f) break;
		else ans++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16234

/*
Linked site says it can be solved bfs.
But, I thought dfs is easier solution.
So I solve with dfs.
*/