#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100001;
vector<int> adj[MAX];
int N, D[MAX], A, B, idx = 0, ans = 1, S[MAX];
bool v[MAX];
bool cmp(int a, int b)
{
	return S[a] < S[b];
}
void dfs(int here)
{
	if (D[idx] != here)
	{
		ans = 0;
		return;
	}
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		++idx;
		dfs(there);
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
	for (int i = 0; i < N; i++)
	{
		cin >> D[i];
		S[D[i]] = i;
	}
	for (int i = 1; i <= N; i++)
		sort(adj[i].begin(), adj[i].end(), cmp);
	v[1] = true;
	dfs(1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16964