#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1000000007;
int N, M, U, V, B, K, adj[251][251], S, E;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (i == j) adj[i][j] = 0;
			else adj[i][j] = INF;
		}
	for (int i = 0; i < M; i++)
	{
		cin >> U >> V >> B;
		adj[U][V] = 0;
		adj[V][U] = (B == 0);
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	cin >> K;
	while (K--)
	{
		cin >> S >> E;
		cout << adj[S][E] << '\n';
	}
}

// https://www.acmicpc.net/problem/11562