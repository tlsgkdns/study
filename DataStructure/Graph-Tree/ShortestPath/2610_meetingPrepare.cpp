#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000

using namespace std;
vector<bool> v;
vector<vector<int>> meet;
vector<int> team, ans, mn, tmp;
int n, m;
void dfs(int t)
{
	for (int i = 1; i <= n; i++)
	{
		if (meet[i][t] != INF && !v[i] && i != t)
		{
			v[i] = true;
			team[i] = team[t];
			dfs(i);
		}
	}
}
int main()
{
	cin >> n >> m;
	meet.resize(n + 1, vector<int>(n + 1, INF)); v.resize(n + 1, false);
	team.resize(n + 1); mn.resize(n + 1, INF); ans.resize(n + 1, INF);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		meet[a][b] = 1; meet[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
		meet[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (meet[i][k] + meet[k][j] < meet[i][j])
				{
					meet[i][j] = meet[i][k] + meet[k][j];
					meet[j][i] = meet[i][j];
				}

	for (int i = 1; i <= n; i++)
		team[i] = i;
	v[0] = v[1] = true;
	for (int i = 1; i <= n; i++)
		dfs(i);
	for (int i = 1; i <= n; i++)
	{
		int s = -1;
		for (int e : meet[i])	if (e != INF) s = max(s, e);

		if (mn[team[i]] > s)
		{
			ans[team[i]] = i;
			mn[team[i]] = s;
		}
	}
	for (int a : ans)
		if (a != INF) tmp.push_back(a);
	sort(tmp.begin(), tmp.end());
	cout << tmp.size() << '\n';
	for (int i = 0; i < tmp.size(); i++)
		cout << tmp[i] << '\n';
}

// https://www.acmicpc.net/problem/2610