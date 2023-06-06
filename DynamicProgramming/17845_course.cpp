#include <iostream>
#include <algorithm>
using namespace std;

int N, K, I[1001], T[1001];
int dp[10001][2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	bool idx = false;
	for (int i = 0; i < K; i++)
		cin >> I[i] >> T[i];
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j <= N; j++)
			if (j < T[i])
				dp[j][idx] = dp[j][!idx];
			else
				dp[j][idx] = max(dp[j][!idx], dp[j - T[i]][!idx] + I[i]);
		idx = !idx;
	}
	cout << dp[N][!idx] << '\n';
}

// https://www.acmicpc.net/problem/17845