#include <iostream>

using namespace std;
const int MOD = 10000003;
int S[51], N, dp[51][100001];

int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	while (b > 0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> S[i];
		for (int j = 1; j <= 100000; j++) dp[i][j] = dp[i - 1][j];
		dp[i][S[i]]++;
		for (int j = 1; j <= 100000; j++)
		{
			if (dp[i - 1][j] > 0)
			{
				int g = gcd(S[i], j);
				dp[i][g] = (dp[i][g] + dp[i - 1][j]) % MOD;
			}
		}
	}
	cout << dp[N][1] << '\n';
}

// https://www.acmicpc.net/problem/1750