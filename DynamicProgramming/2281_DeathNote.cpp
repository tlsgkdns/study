#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 100000000000;
int N, M, L[1001];
ll dp[1001][1001];

ll solve(int idx, int cur)
{
	if (idx == N)
		return 0;
	ll& ret = dp[idx][cur];
	if (ret >= 0) return ret;
	ret = INF;
	if (cur >= L[idx] + 1) ret = min(ret, solve(idx + 1, cur - L[idx] - 1));
	ret = min(ret, solve(idx + 1, M - L[idx]) + (cur * cur));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> L[i];
	cout << solve(1, M - L[0]) << '\n';
}

// https://www.acmicpc.net/problem/2281