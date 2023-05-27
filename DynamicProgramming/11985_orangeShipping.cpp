#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
int N, M, K;
const ll MAX = 100000000000000;
ll A[20001], dp[20001];

ll solve(int idx)
{
	if (idx == N) return 0;
	ll& ret = dp[idx];
	if (ret >= 0) return ret;
	ret = MAX;
	ll s = 0, a = 0, b = MAX;
	for (int i = idx; i < min(N, idx + M); i++)
	{
		a = max(a, A[i]); b = min(b, A[i]);
		ret = min(ret, solve(i + 1) + K + (i - idx + 1) * (a - b));
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	cout << solve(0) << '\n';
}

// https://www.acmicpc.net/problem/11985