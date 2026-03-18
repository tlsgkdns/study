#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N, dp[51];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	dp[0] = dp[1] = 1;
	cin >> N;
	for (int i = 2; i <= N; i++)
		dp[i] += (dp[i - 1] + dp[i - 2] + 1) % 1000000007;
	cout << dp[N] << '\n';
}

// https://www.acmicpc.net/problem/17175