#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> sh;
vector<int> adj[101], d;
vector<bool> v;
bool dfs(int here)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		if (d[there] == -1 || dfs(d[there]))
		{
			d[there] = here;
			return true;
		}
	}
	return false;
}
int N, SZ, SP, IT, a;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	d.resize(2 * N, -1); v.resize(2 * N, false);
	for (int n = 0; n < N; n++)
	{
		cin >> SZ >> SP >> IT;
		for (int i = 0; i < sh.size(); i++)
			if (get<0>(sh[i]) <= SZ && get<1>(sh[i]) <= SP && get<2>(sh[i]) <= IT)
			{
				adj[n].push_back(i);
				adj[n + N].push_back(i);
			}
			else if (get<0>(sh[i]) >= SZ && get<1>(sh[i]) >= SP && get<2>(sh[i]) >= IT)
			{
				adj[i].push_back(n);
				adj[i + N].push_back(n);
			}
		sh.push_back(tie(SZ, SP, IT));
	}
	for (int i = 0; i < 2 * N; i++)
	{
		v = vector<bool>(2 * N, false);
		if (dfs(i)) a++;
	}
	cout << N - a << '\n';
}

// https://www.acmicpc.net/problem/1671