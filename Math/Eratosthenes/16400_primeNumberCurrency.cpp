#include <iostream>

using namespace std;

bool v[40003];
long long N, dp[40003];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 2; i * i <= 40001; i++)
		if (!v[i])
		{
			for (int n = i * i; n <= 40001; n += i)
				v[n] = true;
		}
	dp[0] = 1;
	for (int i = 2; i <= 40001; i++)
		if (!v[i])
		{
			for (int n = i; n <= 40001; n++)
				dp[n] = (dp[n] + dp[n - i]) % 123456789;
		}
	cout << dp[N] << '\n';
}

// https://www.acmicpc.net/problem/16400