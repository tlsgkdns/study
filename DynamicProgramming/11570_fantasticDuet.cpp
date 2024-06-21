#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int N, P[2002], dp[2002][2002];
const int INF = 2000000007;
int solve(int idx1, int idx2)
{
	if (idx1 == N || idx2 == N) return 0;
	int& ret = dp[idx1][idx2];
	if (ret >= 0) return ret;
	ret = INF;
	int nxt = max(idx1 + 1, idx2 + 1);
	ret = min(ret, solve(nxt, idx2) + ((idx1 == 0) ? 0 : abs(P[idx1] - P[nxt])));
	ret = min(ret, solve(idx1, nxt) + ((idx2 == 0) ? 0 : abs(P[idx2] - P[nxt])));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i];
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/11570