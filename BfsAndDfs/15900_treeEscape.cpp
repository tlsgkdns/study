#include <iostream>
#include <vector>
using namespace std;

int N, A, B;
long long S = 0;
vector<int> adj[500001];
bool v[500001];
void dfs(int here, int d)
{
	if (adj[here].size() == 1 && v[adj[here][0]])
	{
		S += d;
		return;
	}
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		dfs(there, d + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	v[1] = true;
	dfs(1, 0);
	if (S % 2 == 0) cout << "No\n";
	else cout << "Yes\n";
}

// https://www.acmicpc.net/problem/15900