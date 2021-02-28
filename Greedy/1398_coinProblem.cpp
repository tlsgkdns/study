#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector<int> dp;

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	vector<ll> input(t), ans;
	vector<int> dp(100);
	for (int i = 0; i < t; i++)
	{
		cin >> input[i];
	}
	for (int num = 0; num < 100; num++)
	{
		if (num < 10)
			dp[num] = num;
		else if (num < 25)
			dp[num] = dp[num - 10] + 1;
		else
			dp[num] = min(dp[num - 25] + 1, dp[num - 10] + 1);
	}
	for (ll n : input)
	{
		ll a = 0;
		while (n != 0)
		{
			int tail = n % 100;
			n /= 100;
			a += dp[tail];
		}
		ans.push_back(a);
	}
	for (ll a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/1398

/*
problem of idea
just divide it into two number
I thought how to solve this problem for all day long
*/