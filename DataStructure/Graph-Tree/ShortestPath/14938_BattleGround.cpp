#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
int N, M, T[101], A, B, L, R, adj[101][101], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) cin >> T[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (i != j)
				adj[i][j] = INF;

	for (int i = 0; i < R; i++)
	{
		cin >> A >> B >> L;
		adj[A - 1][B - 1] = L;
		adj[B - 1][A - 1] = L;
	}
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	for (int i = 0; i < N; i++)
	{
		int s = 0;
		for (int j = 0; j < N; j++)
			if (adj[i][j] <= M)
				s += T[j];
		ans = max(ans, s);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14938