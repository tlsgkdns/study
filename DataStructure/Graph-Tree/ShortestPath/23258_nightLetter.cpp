#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1000000007;
int adj[301][301][301];
int N, Q, S, E, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> adj[i][j][0];
			if (i != j && adj[i][j][0] == 0) adj[i][j][0] = INF;
		}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				adj[i][j][k] = min(adj[i][j][k - 1], adj[i][k][k - 1] + adj[k][j][k - 1]);
	while (Q--)
	{
		cin >> C >> S >> E;
		int ans = (adj[S][E][C - 1] >= INF) ? -1 : adj[S][E][C - 1];
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/23258