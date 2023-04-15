#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000001;
int N, M, Q, S, T, A, B, D, a, b;
vector<pair<int, int>> C;
int adj[501][501], P[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		C.push_back({ a, i });
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			adj[i][j] = INF;
			P[i][j] = max(C[i - 1].first, C[j - 1].first);
		}
	sort(C.begin(), C.end());
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> D;
		adj[A][B] = D;
		adj[B][A] = D;
	}
	for (int idx = 0; idx < N; idx++)
	{
		int k = C[idx].second;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (P[i][j] + adj[i][j] > max(P[i][j], max(P[i][k], P[k][j])) + adj[i][k] + adj[k][j])
				{
					P[i][j] = max(P[i][j], max(P[i][k], P[k][j]));
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
	}
	while (Q--)
	{
		cin >> S >> T;
		int ans = adj[S][T] + P[S][T];
		if (ans >= INF) ans = -1;
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/1602