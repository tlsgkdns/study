#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1000000007;
int dp[101][501], N, M, A, B, X, Y, L[501];

int solve(int here, int idx)
{
	if (idx == M) return abs(here - B) * Y;
	int& ret = dp[here][idx];
	if (ret >= 0) return ret;
	ret = INF;
	if (L[idx] == here - 1) ret = min(ret, solve(here - 1, idx + 1));
	if (L[idx] == here) ret = min(ret, solve(here + 1, idx + 1));
	if (L[idx] != here - 1 && L[idx] != here) ret = min(ret, solve(here, idx + 1));
	else ret = min(ret, solve(here, idx + 1) + X);
	if (here > 1) ret = min(ret, solve(here - 1, idx) + Y);
	if (here < N) ret = min(ret, solve(here + 1, idx) + Y);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	cin >> A >> B >> X >> Y;
	for (int i = 0; i < M; i++) cin >> L[i];
	cout << solve(A, 0) << '\n';
}

// https://www.acmicpc.net/problem/2008