#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;
int D[100001][2], P[100001][2], C, L[2], S[2], N, dp[100001][2];

int solve(int idx, bool st)
{
	if (idx == N - 1) return S[st];
	int& ret = dp[idx][st];
	if (ret >= 0) return ret;
	ret = INF;
	ret = min(ret, solve(idx + 1, st) + D[idx][st]);
	ret = min(ret, solve(idx + 1, !st) + P[idx][st]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> C;
	while (C--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> N >> L[0] >> L[1] >> S[0] >> S[1];
		for (int i = 0; i < N - 1; i++) cin >> P[i][0];
		for (int i = 0; i < N - 1; i++) cin >> D[i][0];
		for (int i = 0; i < N - 1; i++) cin >> P[i][1];
		for (int i = 0; i < N - 1; i++) cin >> D[i][1];
		cout << min(solve(0, 0) + L[0], solve(0, 1) + L[1]) << '\n';
	}
}

// https://www.acmicpc.net/problem/3976