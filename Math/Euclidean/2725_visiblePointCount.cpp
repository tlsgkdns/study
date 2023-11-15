#include <iostream>
#include <cstring>
using namespace std;

int C, N, dp[1001];

int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	while (b != 0)
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
	memset(dp, -1, sizeof(dp));
	cin >> C;
	dp[0] = 1;
	for (int i = 1; i < 1001; i++)
	{
		dp[i] = dp[i - 1];
		for (int j = 0; j < i; j++)
			if (gcd(i, j) == 1) dp[i] += 2;
	}
	for (int i = 0; i < C; i++)
	{
		cin >> N;
		cout << dp[N] << '\n';
	}
}

// https://www.acmicpc.net/problem/2725