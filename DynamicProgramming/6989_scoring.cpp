#include <iostream>
#include <bitset>
using namespace std;

const int MAX = 1140000;
int N, K, S[152], acc[152], score[152][152];
bitset<MAX> dp[152];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	acc[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> S[i];
		acc[i] = acc[i - 1] + S[i];
	}
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j++)
			score[i][j] = score[i][j - 1] + acc[j] - acc[i - 1];
	cin >> K;
	if (score[1][N] < K) cout << K << '\n';
	else
	{
		dp[0].set(0);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= i + 1; j++)
				if (j <= 2)
					dp[i].set(score[j][i]);
				else
					dp[i] |= (dp[j - 2] << (score[j][i]));
		int ans = K;
		while (dp[N].test(ans)) ans++;
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/6989