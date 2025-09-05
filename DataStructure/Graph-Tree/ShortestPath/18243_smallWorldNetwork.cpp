#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 1e9 + 7;
int adj[101][101], A, B, N, K;
string ans = "Small World!\n";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			adj[i][j] = INF;
	for (int i = 0; i < K; i++)
	{
		cin >> A >> B;
		adj[A][B] = 1;
		adj[B][A] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (adj[i][j] > 6)
			{
				ans = "Big World!\n";
				break;
			}
	cout << ans;
}

// https://www.acmicpc.net/problem/18243