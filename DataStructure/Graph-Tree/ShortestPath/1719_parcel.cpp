#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000001;
int adj[201][201], dp[201][201], ans[201][201];
int N, M, A, B, C;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			adj[i][j] = INF;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A][B] = min(C, adj[A][B]);
		adj[B][A] = min(C, adj[B][A]);
		dp[A][B] = B;
		dp[B][A] = A;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
				{
					adj[i][j] = adj[i][k] + adj[k][j];
					dp[i][j] = dp[i][k];
				}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dp[i][j] < 0 || i == j) cout << "- ";
			else cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/1719