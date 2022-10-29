#include <iostream>
#include <vector>
using namespace std;

int N, M, A, B, ans = 0;
bool adj[501][501];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A][B] = true;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (adj[i][k] && adj[k][j])
					adj[i][j] = true;

	for (int n = 1; n <= N; n++)
	{
		int cnt = 0;
		for (int i = 1; i <= N; i++)
			cnt += (adj[n][i] || adj[i][n]);
		ans += (cnt == N - 1);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/6156