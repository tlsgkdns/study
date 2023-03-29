#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj[11];
int N, C[11], P, A, D, U[11], ans = 1000000001;
bool v[11];

void solve(int d, int s)
{
	if (d == N)
	{
		ans = min(ans, s);
		return;
	}
	int u[11] = { 0, };
	for (int i = 1; i <= N; i++)
		if (v[i])
			for (int idx = 0; idx < adj[i].size(); idx++)
				u[adj[i][idx].first] += adj[i][idx].second;
	for (int i = 1; i <= N; i++)
	{
		if (v[i]) continue;
		v[i] = true;
		solve(d + 1, s + max(C[i] - u[i], 1));
		v[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> C[i];
	for (int i = 1; i <= N; i++)
	{
		cin >> P;
		while (P--)
		{
			cin >> A >> D;
			adj[i].push_back({ A, D });
		}
	}
	solve(0, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/24954