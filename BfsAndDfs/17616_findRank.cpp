#include <iostream>
#include <vector>
using namespace std;

vector<int> adj1[100001], adj2[100001];
bool v1[100001], v2[100001];
int N, M, X, A, B;

int dfs(int here)
{
	int s = 0;
	for (int i = 0; i < adj1[here].size(); i++)
	{
		int there = adj1[here][i];
		if (v1[there]) continue;
		v1[there] = true;
		s += dfs(there) + 1;
	}
	return s;
}
int dfs2(int here)
{
	int s = 0;
	for (int i = 0; i < adj2[here].size(); i++)
	{
		int there = adj2[here][i];
		if (v2[there]) continue;
		v2[there] = true;
		s += dfs2(there) + 1;
	}
	return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj1[A].push_back(B);
		adj2[B].push_back(A);
	}
	v1[X] = true; v2[X] = true;
	cout << dfs2(X) + 1 << " " << N - dfs(X) << '\n';
}

// https://www.acmicpc.net/problem/17616