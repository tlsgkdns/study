#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M;
int val[100001], ac[100001], dp[100001][2];
int solve(int idx, bool g)
{
	if (idx > N) return 0;
	int& ret = dp[idx][g];
	if (ret >= 0) return ret;
	ret = 0;
	if (g)
		ret = max(ret, solve(idx + 1, g) + val[idx]);
	else if (idx <= N - M + 1)
		ret = max(ret, max(solve(idx + 1, g), solve(idx + M, true) + ac[idx + M - 1] - ac[idx - 1]));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; i++)
	{
		cin >> val[i];
		ac[i] = ac[i - 1] + val[i];
	}
	cout << solve(1, false) << '\n';
}

// https://www.acmicpc.net/problem/2208