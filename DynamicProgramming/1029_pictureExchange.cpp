#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, dp[33000][10][16];
char P[17][17];

int solve(int b, int p, int idx)
{
	int& ret = dp[b][p][idx];
	if (ret >= 0) return ret;
	ret = 1;
	for (int i = 0; i < N; i++)
	{
		if (b & (1 << i) || P[idx][i] - '0' < p) continue;
		ret = max(ret, solve(b | (1 << i), P[idx][i] - '0', i) + 1);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> P[i][j];
	cout << solve(1, 0, 0) << '\n';
}

// https://www.acmicpc.net/problem/1029