#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int INF = 1000000007;
int N, M, dp[1001][1001], A[1001], B[1001];

int solve(int idx, int cnt)
{
	if (cnt == M) return 0;
	if (idx == N) return INF;
	int& ret = dp[idx][cnt];
	if (ret >= 0) return ret;
	ret = INF;
	ret = solve(idx + 1, cnt + 1) + abs(A[idx] - B[cnt]);
	ret = min(ret, solve(idx + 1, cnt));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];
	sort(A, A + N); sort(B, B + M);
	if (N < M)
	{
		swap(A, B);
		swap(N, M);
	}
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/1727