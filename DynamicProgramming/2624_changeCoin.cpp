#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[10001][101], T, K;
int P[101], N[101];
int solve(int money, int idx)
{
	if (money == 0) return 1;
	if (money < 0 || idx >= K) return 0;
	int& ret = dp[money][idx];
	if (ret >= 0) return ret;
	ret = 0;
	int l = min(money / P[idx], N[idx]);
	for (int i = 0; i <= l; i++)
		ret += solve(money - i * P[idx], idx + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> T >> K;
	for (int i = 0; i < K; i++)
		cin >> P[i] >> N[i];
	cout << solve(T, 0) << '\n';
}

// https://www.acmicpc.net/problem/2624