#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100001;

vector<int> adj[MAX];

int N, S, D, X, Y, L[MAX];
bool v[MAX];

int dfs(int here)
{
	int l = 0;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		l = max(dfs(there) + 1, l);
	}
	L[here] = l;
	return l;
}
int solve(int here)
{
	if (L[here] <= D) return 0;
	int ret = 0;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there] || L[there] < D) continue;
		v[there] = true;
		ret += solve(there) + 2;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(L, -1, sizeof(L));
	cin >> N >> S >> D;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> X >> Y;
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}
	v[S] = true;
	dfs(S);
	memset(v, false, sizeof(v));
	v[S] = true;
	cout << solve(S) << '\n';
}

// https://www.acmicpc.net/problem/19542