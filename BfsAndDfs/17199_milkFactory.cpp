#include <iostream>
#include <vector>
using namespace std;

int N, a, b;
vector<vector<int>> adj;
vector<vector<bool>> v;
void dfs(int root, int here)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[root][there]) continue;
		v[root][there] = true;
		dfs(root, there);
		dfs(there, there);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; v.resize(N + 1, vector<bool>(N + 1, false));
	adj.resize(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
	}
	int ans = -1;
	for (int n = 1; n <= N; n++)
	{
		if (v[n][n]) continue;
		v[n][n] = true;
		dfs(n, n);
	}
	for (int c = 1; c <= N; c++)
	{
		bool flag = true;
		for (int r = 1; r <= N; r++)
		{
			if (!v[r][c])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			ans = c;
			break;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17199