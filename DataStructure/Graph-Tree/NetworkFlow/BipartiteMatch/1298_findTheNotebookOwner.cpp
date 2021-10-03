#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, a, b, ans = 0;

vector<vector<int>> notebook;
vector<bool> v;
vector<int> cap;
bool dfs(int x)
{
	for (int i = 0; i < notebook[x].size(); i++)
	{
		int t = notebook[x][i];
		if (v[t]) continue;
		v[t] = true;
		if (cap[t] == 0 || dfs(cap[t]))
		{
			cap[t] = x;
			return true;
		}
	}
	return false;
}
int main()
{
	cin >> n >> m;
	notebook.resize(n + 1);
	cap.resize(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		notebook[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
	{
		v = vector<bool>(n + 1, false);
		if (dfs(i)) ans++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1298