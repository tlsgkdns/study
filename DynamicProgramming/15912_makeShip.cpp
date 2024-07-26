#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const ll INF = 100000000000000007;
ll dp[1001], dp2[1001][1001], dp3[1001][1001], W[1001], E[1001];
int N;

ll solve(int idx)
{
	if (idx == N) return 0;
	ll& ret = dp[idx];
	if (ret >= 0) return ret;
	ret = INF;
	for (int i = idx; i < N; i++)
		ret = min(ret, solve(i + 1) + dp2[idx][i] * dp3[idx][i]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> W[i];
	for (int i = 0; i < N; i++) cin >> E[i];
	for (int l = 0; l < N; l++)
		for (int r = l; r < N; r++)
			if (l == r)
			{
				dp2[l][r] = W[l];
				dp3[l][r] = E[l];
			}
			else
			{
				dp2[l][r] = max(W[r], dp2[l][r - 1]);
				dp3[l][r] = max(E[r], dp3[l][r - 1]);
			}
	cout << solve(0) << '\n';
}

// https://www.acmicpc.net/problem/15912