#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1001;
vector<int> v;
int routes[MAX][MAX];
vector<int> adj[MAX];
int indegree[MAX][MAX];
int N, cnt = 0;
bool impossible = false;
int dfs1(int here)
{
	int ret = 1;
	for (int there = 1; there <= N; there++)
		if (indegree[here][there] > 0 && !v[there])
		{
			v[there] = true;
			ret += dfs1(there);
		}
	return ret;
}
void dfs2(int here)
{
	while ((int)adj[here].size() > 0)
	{
		int there = adj[here].back();
		int u = here, v = there;
		if (u > v) swap(u, v);
		if (indegree[u][v] == 0)
		{
			adj[here].pop_back();
			continue;
		}
		indegree[u][v]--;
		dfs2(there);
	}
	cout << here << " ";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; v.resize(N + 1, false);
	for (int i = 1; i <= N; i++)
	{
		int s = 0;
		for (int j = 1; j <= N; j++)
		{
			cin >> indegree[i][j];
			s += indegree[i][j];
			if (i >= j || indegree[i][j] <= 0) continue;
			for (int n = 0; n < indegree[i][j]; n++)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
		if (s % 2 == 1) impossible = true;
	}
	v[1] = true;
	if (impossible || N != dfs1(1)) cout << -1 << '\n';
	else
	{
		dfs2(1);
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/1199