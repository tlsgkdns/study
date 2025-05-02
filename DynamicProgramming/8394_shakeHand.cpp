#include <iostream>
#include <cstring>

using namespace std;

int N, dp[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	dp[1] = dp[2] = 1;
	for (int i = 0; i < N; i++)
		dp[i % 3] = (dp[(i + 1) % 3] + dp[(i + 2) % 3]) % 10;
	cout << dp[(N + 1) % 3] << '\n';
}

// https://www.acmicpc.net/problem/8394