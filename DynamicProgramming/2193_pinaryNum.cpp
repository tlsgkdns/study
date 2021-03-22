#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> dp;

long long solve(int num, bool re)
{
	if (num == 0) return 1;
	if (dp[num][re] != -1) return dp[num][re];
	if (re)
		return dp[num][re] = solve(num - 1, false);
	else
		return dp[num][re] = solve(num - 1, true) + solve(num - 1, false);
}
int main()
{
	int n;
	cin >> n;
	dp.resize(n + 1, vector<long long>(2, -1));
	cout << solve(n - 1, true) << '\n';
}

// https://www.acmicpc.net/problem/2193

/*
dataStructure is bigger than I expected.
*/