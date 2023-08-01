#include <iostream>

using namespace std;
int T, M, N, G[101][101], B[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> G[i][j];
		int ans = 0;
		for (int i = 0; i < M; i++) B[i] = N - 1;
		for (int i = N - 1; i >= 0; i--)
			for (int j = 0; j < M; j++)
				if (G[i][j])
				{
					ans += B[j] - i;
					--B[j];
				}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/9455