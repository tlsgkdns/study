#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
const int MAX = 40001;
vector<pair<int, int>> adj[40001];
int dp[MAX][20], N, M, A, B, C, L;
int D[MAX], P[MAX];

void getTree(int here, int parent)
{
	D[here] = D[parent] + 1;
	dp[here][0] = parent;
	for (int i = 1; i <= L; i++)
		dp[here][i] = dp[dp[here][i - 1]][i - 1];
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		if (there != parent)
			getTree(there, here);
	}
}
void dfs(int here, int parent, ll c)
{
	P[here] = c;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		int cost = adj[here][i].second;
		if (there == parent) continue;
		dfs(there, here, c + cost);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	L = (int)ceil(log2(MAX));
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	D[0] = D[1] = -1;
	getTree(1, 0);
	dfs(1, 0, 0);
	cin >> M;
	while (M--)
	{
		cin >> A >> B;
		ll ans = P[A] + P[B];
		if (D[A] != D[B])
		{
			if (D[A] > D[B]) swap(A, B);
			for (int i = L; i >= 0; i--)
				if (D[A] <= D[dp[B][i]])
					B = dp[B][i];
		}
		int lca = A;
		if (A != B)
		{
			for (int i = L; i >= 0; i--)
			{
				if (dp[A][i] != dp[B][i])
				{
					A = dp[A][i];
					B = dp[B][i];
				}
				lca = dp[A][i];
			}
		}
		ans -= P[lca] * 2;
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/1761