#include <iostream>
#include <algorithm>

using namespace std;
int N, C[1001], dp[1001], ans = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> C[i];
		dp[i] = 1;
	}
	for (int i = 1; i < N; i++)
		for (int j = 0; j < i; j++)
			if (C[j] < C[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11568