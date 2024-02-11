#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string S1, S2;
int dp[1001][1001];
int solve(int idx1, int idx2)
{
	if (idx1 == S1.size() && idx2 == S2.size()) return 0;
	int& ret = dp[idx1][idx2];
	if (ret >= 0) return ret;
	ret = 1000000007;
	if (idx1 < S1.size() && idx2 < S2.size()) ret = min(ret, solve(idx1 + 1, idx2 + 1) + (S1[idx1] != S2[idx2]));
	if (idx2 < S2.size()) ret = min(ret, solve(idx1, idx2 + 1) + 1);
	if (idx1 < S1.size()) ret = min(ret, solve(idx1 + 1, idx2) + 1);
	return ret;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> S1 >> S2;
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/15483