#include <iostream>
#include <vector>
using namespace std;

char seat[5][5];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int ans = 0;
int dfs(vector<vector<bool>>& v, vector<vector<bool>>& s, int y, int x)
{
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny == 5 || nx == 5 || ny < 0 || nx < 0
			|| v[ny][nx] || !s[ny][nx]) continue;
		v[ny][nx] = true;
		ret += dfs(v, s, ny, nx) + 1;
	}
	return ret;
}
bool satisfy(vector<vector<bool>>& selected)
{
	int ret = 0, s = 0;
	bool f = false;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (selected[i][j] && seat[i][j] == 'S') s++;
	if (s < 4) return false;
	vector<vector<bool>> v(5, vector<bool>(5, false));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			if (selected[i][j])
			{
				ret = dfs(v, selected, i, j);
				return (ret == 7);
			}
	}
	return false;
}
void solve(vector<vector<bool>>& selected, int idx, int d)
{
	if (d == 7)
	{
		if (satisfy(selected))
			ans++;
		return;
	}
	for (int i = idx; i < 25; i++)
	{
		selected[i / 5][i % 5] = true;
		solve(selected, i + 1, d + 1);
		selected[i / 5][i % 5] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> seat[i][j];
	vector<vector<bool>> select(5, vector<bool>(5, false));
	solve(select, 0, 0);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1941