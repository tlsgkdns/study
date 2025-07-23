#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[50001], N;

int solve(int num)
{
	if (num == 0) return 0;
	int& ret = dp[num];
	if (ret >= 0) return ret;
	ret = 1e9 + 7;
	for (int i = 1; i * i <= num; i++)
		ret = min(ret, solve(num - (i * i)) + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << solve(N) << '\n';
}

// https://www.acmicpc.net/problem/17626