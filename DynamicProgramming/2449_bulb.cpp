#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
int dp[201][201], N, K, bulb[201];

int solve(int s, int e)
{
	if (s == e) return 0;
	int& ret = dp[s][e];
	if (ret >= 0) return ret;
	ret = INF;
	for (int i = s; i < e; i++)
		ret = min(ret, solve(s, i) + solve(i + 1, e) + (bulb[s] != bulb[i + 1]));
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> bulb[i];
	cout << solve(0, N - 1) << '\n';
}

// https://www.acmicpc.net/problem/2449