#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int NINF = -1000000001;
int N, K, dp[101][100001], A[101], B[101], C[101], D[101];

int solve(int idx, int t)
{
	if (t > K) return NINF;
	if (idx == N) return 0;
	int& ret = dp[idx][t];
	if (ret > NINF) return ret;
	ret = max(solve(idx + 1, t + A[idx]) + B[idx], solve(idx + 1, t + C[idx]) + D[idx]);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= K; j++)
			dp[i][j] = NINF;
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/14863