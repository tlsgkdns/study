#include <iostream>
#include <vector>
using namespace std;

vector<int> coin;
vector<int> dp;
int n, k;

int main()
{
	cin >> n >> k;
	coin.resize(n); dp.resize(k + 1, 0);
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		if (coin[i] > k) continue;
		for (int j = coin[i]; j <= k; j++)
			dp[j] += dp[j - coin[i]];
	}
	cout << dp[k] << '\n';
}

// https://www.acmicpc.net/problem/2293