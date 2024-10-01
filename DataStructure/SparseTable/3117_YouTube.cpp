#include <iostream>

using namespace std;
const int mL = 32;
int N, K, M, Y[100001], dp[mL][100001], S[100001], ans[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++) cin >> S[i];
	for (int i = 1; i <= K; i++) cin >> dp[0][i];
	for (int i = 1; i < mL; i++)
		for (int j = 1; j <= K; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
	for (int i = 1; i <= N; i++)
	{
		int idx = 0, r = M - 1, now = S[i];
		while (r > 0)
		{
			if (r % 2 > 0) now = dp[idx][now];
			++idx;
			r /= 2;
		}
		ans[i] = now;
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/3117