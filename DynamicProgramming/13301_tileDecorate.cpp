#include <iostream>

using namespace std;

long long dp[85], dp2[85];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	dp[1] = 1; dp2[1] = 4;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp2[i] = dp2[i - 1] + 2 * dp[i];
	}
	cout << dp2[N] << '\n';
}

// https://www.acmicpc.net/problem/13301