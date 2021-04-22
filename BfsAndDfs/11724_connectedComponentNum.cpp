#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> v;
vector<bool> c;
int n, m, a1, a2, ans = 0;
void dfs(int a)
{
	for (int i = 1; i < n + 1; i++)
	{
		if (v[a][i] && !c[i])
		{
			c[i] = true;
			dfs(i);
		}
	}
}
int main()
{
	cin >> n >> m;
	v.resize(n + 1, vector<bool>(n + 1, false));
	c.resize(n + 1, false);
	for (int i = 0; i < m; i++)
	{
		cin >> a1 >> a2;
		v[a1][a2] = true;
		v[a2][a1] = true;
	}
	for (int i = 1; i < n + 1; i++)
	{
		if (c[i]) continue;
		dfs(i);
		ans++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11724