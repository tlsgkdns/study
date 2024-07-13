#include <iostream>
#include <vector>
using namespace std;

int N, M, I, W, P, S[100001];

vector<int> adj[100001];
void dfs(int here)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		S[there] += S[here];
		dfs(there);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> P;
		if (P < 0) continue;
		adj[P].push_back(i);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> I >> W;
		S[I] += W;
	}
	dfs(1);
	for (int i = 1; i <= N; i++) cout << S[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/14267