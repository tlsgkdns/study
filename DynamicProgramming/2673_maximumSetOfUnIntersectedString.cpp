#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int A, B, N, dp[101][102];
int L[101];
int solve(int idx, int lm)
{
	if (idx >= lm) return 0;
	int& ret = dp[idx][lm];
	if (ret != -1) return ret;
	if (L[idx] == -1 || L[idx] > lm) return ret = solve(idx + 1, lm);
	else return ret = max(solve(idx + 1, lm), solve(L[idx], lm) + solve(idx + 1, L[idx]) + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp)); memset(L, -1, sizeof(L));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		if (A > B) swap(A, B);
		L[A] = B;
	}
	cout << solve(0, 101) << '\n';
}

// https://www.acmicpc.net/problem/2673