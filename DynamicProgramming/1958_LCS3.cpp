#include <iostream>
#include <cstring>

using namespace std;

string S1, S2, S3;
int dp[101][101][101];

int solve(int idx1, int idx2, int idx3)
{
	int& ret = dp[idx1][idx2][idx3];
	if (ret >= 0) return ret;
	ret = 0;
	if (idx1 < S1.size()) ret = max(ret, solve(idx1 + 1, idx2, idx3));
	if (idx2 < S2.size()) ret = max(ret, solve(idx1, idx2 + 1, idx3));
	if (idx3 < S3.size()) ret = max(ret, solve(idx1, idx2, idx3 + 1));
	if (idx1 < S1.size() && idx2 < S2.size() && idx3 < S3.size()
		&& S1[idx1] == S2[idx2] && S2[idx2] == S3[idx3])
		ret = max(ret, solve(idx1 + 1, idx2 + 1, idx3 + 1) + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> S1 >> S2 >> S3;
	cout << solve(0, 0, 0) << '\n';
}

// https://www.acmicpc.net/problem/1958