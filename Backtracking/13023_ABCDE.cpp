#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[2001];
bool v[2001];
int N, M, D = 0, A, B;
vector<int> F;
void dfs(int here, int d)
{
	if (D >= 5) return;
	if (D < d)
	{
		D = d;
		F = vector<int>();
		F.push_back(here);
	}
	else if (D == d)
		F.push_back(here);
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		dfs(there, d + 1);
		v[there] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	while (M--)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	for (int i = 0; i < N; i++)
	{
		if (v[i]) continue;
		v[i] = true;
		dfs(i, 1);
	}
	memset(v, false, sizeof(v));
	vector<int> R = F;
	for (int i = 0; i < R.size(); i++)
	{
		v[R[i]] = true;
		dfs(R[i], 1);
	}
	cout << (D >= 5) << '\n';
}

// https://www.acmicpc.net/problem/13023