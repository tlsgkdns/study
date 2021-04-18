#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
int dp[1000001][21];

int solve(int num, int prev)
{
	if (num < 0) return 0;
	if (num == 0) return 1;
	int& ret = dp[num][prev];
	if (ret > 0) return ret % 1000000000;
	for (int i = prev; i >= 0; i--)
	{
		ret += solve(num - pow(2, i), i) % 1000000000;
		ret %= 1000000000;
	}
	return ret % 1000000000;
}
int main()
{
	cin >> n;
	cout << solve(n, 20) << '\n';
}

// https://www.acmicpc.net/problem/2410