#include <iostream>

using namespace std;
int N, dp[1001], T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int n = 1; n <= 1000; n++)
	{
		int cnt = 0;
		for (int k = 2; k <= n; k++)
		{
			int tmp = n;
			while (tmp % k == 0)
			{
				tmp /= k;
				++cnt;
			}
		}
		dp[n] = cnt;
	}
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << dp[N] << '\n';
	}
}

// https://www.acmicpc.net/problem/1975