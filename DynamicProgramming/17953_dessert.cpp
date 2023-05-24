#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[12][100001], N, M, V[12][100001];
int solve(int idx, int prv)
{
	if (idx == N) return 0;
	int& ret = dp[prv][idx];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = 1; i <= M; i++)
		ret = max(ret, solve(idx + 1, i) + ((prv == i) ? V[i][idx] / 2 : V[i][idx]));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
		for (int j = 0; j < N; j++)
			cin >> V[i][j];
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/17953