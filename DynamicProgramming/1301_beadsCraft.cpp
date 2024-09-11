#include <iostream>
#include <cstring>

using namespace std;

int N, A[6] = { 0, 0, 0, 0, 0, 0 };
long long dp[11][11][11][11][11][6][6];
long long solve(int m1, int m2, int m3, int m4, int m5, int p, int pp)
{
	if (m1 == 0 && m2 == 0 && m3 == 0 && m4 == 0 && m5 == 0) return 1;
	long long& ret = dp[m1][m2][m3][m4][m5][p][pp];
	if (ret >= 0) return ret;
	ret = 0;
	if (m1 > 0 && p != 1 && pp != 1) ret += solve(m1 - 1, m2, m3, m4, m5, 1, p);
	if (m2 > 0 && p != 2 && pp != 2) ret += solve(m1, m2 - 1, m3, m4, m5, 2, p);
	if (m3 > 0 && p != 3 && pp != 3) ret += solve(m1, m2, m3 - 1, m4, m5, 3, p);
	if (m4 > 0 && p != 4 && pp != 4) ret += solve(m1, m2, m3, m4 - 1, m5, 4, p);
	if (m5 > 0 && p != 5 && pp != 5) ret += solve(m1, m2, m3, m4, m5 - 1, 5, p);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cout << solve(A[0], A[1], A[2], A[3], A[4], 0, 0) << '\n';
}

// https://www.acmicpc.net/problem/1301