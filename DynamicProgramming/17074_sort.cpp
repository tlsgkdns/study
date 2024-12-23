#include <iostream>
#include <cstring>
using namespace std;

int dp[100001][2][2], N, A[100001];

int solve(int idx, bool f1, bool f2)
{
	if (idx > N) return (f2);
	int& ret = dp[idx][f1][f2];
	if (ret >= 0) return ret;
	ret = 0;
	if (!f2) ret += solve(idx + 1, true, true);
	int prv = idx - (f1 + 1);
	if (A[idx] >= A[prv])
		ret += solve(idx + 1, false, f2);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A[0] = -1e9 - 1;
	for (int i = 1; i <= N; i++) cin >> A[i];
	memset(dp, -1, sizeof(dp));
	cout << solve(1, false, false) << '\n';
}

// https://www.acmicpc.net/problem/17074