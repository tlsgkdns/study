#include <iostream>
#include <cstring>
using namespace std;

int N, dp[1001][10];
int solve(int idx, int prv)
{
	if (idx == N) return 1;
	int& ret = dp[idx][prv];
	if (ret >= 0) return ret;
	ret = 0;
	for (int n = prv; n <= 9; n++)
		ret = (solve(idx + 1, n) + ret) % 10007;
	ret %= 10007;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/11057