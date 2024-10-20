#include <iostream>
#include <algorithm>

using namespace std;

int adj[501][501], N, M, A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> adj[i][j];
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	while (M--)
	{
		cin >> A >> B >> C; --A; --B;
		if (adj[A][B] <= C) cout << "Enjoy other party\n";
		else cout << "Stay here\n";
	}
}

// https://www.acmicpc.net/problem/11265