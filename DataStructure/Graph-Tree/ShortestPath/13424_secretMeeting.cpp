#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000001;
int N, M, K, T, A, B, C;
int adj[101][101], F[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		int D = INF, ans = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (i == j) adj[i][j] = 0;
				else adj[i][j] = INF;
			}
		for (int i = 0; i < M; i++)
		{
			cin >> A >> B >> C;
			adj[A][B] = C;
			adj[B][A] = C;
		}
		for (int k = 1; k <= N; k++)
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		cin >> K;
		for (int i = 0; i < K; i++) cin >> F[i];
		for (int i = 1; i <= N; i++)
		{
			int s = 0;
			for (int idx = 0; idx < K; idx++)
				s += adj[F[idx]][i];
			if (D > s)
			{
				D = s;
				ans = i;
			}
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/13424