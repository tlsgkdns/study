#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[10001], N, C[10001];
double M, P[10001];
int solve(int money)
{
	int& ret = dp[money];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = 0; i < N; i++)
	{
		if (money < P[i]) continue;
		ret = max(ret, solve(money - P[i]) + C[i]);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0.0) break;
		memset(dp, -1, sizeof(dp));
		M *= 100;
		for (int i = 0; i < N; i++)
		{
			cin >> C[i] >> P[i];
			P[i] *= 100;
		}
		cout << solve(M) << '\n';
	}
}

// https://www.acmicpc.net/problem/4781