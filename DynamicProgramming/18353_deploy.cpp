#include <iostream>
#include <cstring>

using namespace std;

int N, dp[2001], P[2001], ans = 0;

int solve(int idx)
{
	int& ret = dp[idx];
	if (ret >= 0) return ret;
	ret = 1;
	for (int i = idx + 1; i < N; i++)
		if (P[idx] > P[i])
			ret = max(ret, solve(i) + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i];
	for (int i = 0; i < N; i++) ans = max(ans, solve(i));
	cout << N - ans << '\n';
}

// https://www.acmicpc.net/problem/18353