#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> adj[100001];
int ans[100001];
int N, A, B;
void solve(int here)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (ans[there] >= 0) continue;
		ans[there] = here;
		solve(there);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(ans, -1, sizeof(ans));
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	solve(1);
	for (int i = 2; i <= N; i++) cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/11725