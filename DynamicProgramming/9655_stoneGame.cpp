#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001], N;
int main()
{
	cin >> N;
	dp[0] = -1;
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= 1000; i++)
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
	if (dp[N] % 2) cout << "CY\n";
	else cout << "SK\n";
}

// https://www.acmicpc.net/problem/9655