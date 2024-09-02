#include <iostream>
#include <vector>

using namespace std;
double W;
vector<int> adj[500001];
int N, U, V, cnt = 0;
bool v[500001];

void solve(int here)
{
	if (adj[here].size() == 1 && v[adj[here][0]])
	{
		++cnt;
		return;
	}
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		solve(there);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> W;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}
	v[1] = true;
	solve(1);
	cout << fixed; cout.precision(6);
	cout << W / cnt << '\n';
}

// https://www.acmicpc.net/problem/17073