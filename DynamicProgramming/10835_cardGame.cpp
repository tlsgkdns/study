#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int card1[2001], card2[2001];
int dp[2001][2001], N;
int solve(int idx1, int idx2)
{
	if (idx1 == N || idx2 == N) return 0;
	int& ret = dp[idx1][idx2];
	if (ret != -1) return ret;
	ret = max(ret, solve(idx1 + 1, idx2 + 1));
	ret = max(ret, solve(idx1 + 1, idx2));
	if (card1[idx1] > card2[idx2])
		ret = max(ret, solve(idx1, idx2 + 1) + card2[idx2]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> card1[i];
	for (int i = 0; i < N; i++) cin >> card2[i];
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/10835