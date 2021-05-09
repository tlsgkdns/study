#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> pipe, v;
int r, c, ans = 0;
char ch;
bool dfs(int a, int b)
{
	if (a < 0 || a >= r || !pipe[a][b] || v[a][b]) return false;
	v[a][b] = true;
	if (b == c - 1) return true;
	if (dfs(a - 1, b + 1)) return true;
	if (dfs(a, b + 1)) return true;
	if (dfs(a + 1, b + 1)) return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	pipe.resize(r, vector<bool>(c, false));
	v.resize(r, vector<bool>(c, false));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			cin >> ch;
			if (ch == '.') pipe[i][j] = true;
			else pipe[i][j] = false;
		}
	for (int i = 0; i < r; i++)
		if (dfs(i, 0))
			ans++;

	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/3109