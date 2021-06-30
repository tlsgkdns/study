#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll dp[101];
int main()
{
	int n;
	cin >> n;
	dp[0] = 0; dp[1] = 1;
	dp[2] = 2; dp[3] = 3;
	for (ll i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + 1, i);
		for (int j = 2; j < (i - 2); j++)
			dp[i] = max(dp[i], j * dp[i - (j + 1)]);
	}
	cout << dp[n] << '\n';
}

// https://www.acmicpc.net/problem/11058