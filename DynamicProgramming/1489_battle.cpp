#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
int A[1001], B[1001], dp[51][51][51];

int getScore(int s1, int s2)
{
	if (s1 > s2) return 2;
	if (s1 == s2) return 1;
	return 0;
}
int solve(int idx, int s, int e)
{
	if (idx == N) return 0;
	int& ret = dp[idx][s][e];
	if (ret >= 0) return ret;
	int sc1 = getScore(A[idx], B[s]), sc2 = getScore(A[idx], B[e]);
	ret = max(ret, solve(idx + 1, s + 1, e) + sc1);
	ret = max(ret, solve(idx + 1, s, e - 1) + sc2);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	sort(A, A + N); sort(B, B + N);
	cout << solve(0, 0, N - 1) << '\n';
}

// https://www.acmicpc.net/problem/1489