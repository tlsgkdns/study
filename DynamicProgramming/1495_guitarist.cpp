#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[51][1001], N, M, S, V[51];

int solve(int idx, int v)
{
	if (idx == N) return v;
	int& ret = dp[idx][v];
	if (ret != -1) return ret;
	ret = -2;
	if (V[idx] + v <= M) ret = max(ret, solve(idx + 1, V[idx] + v));
	if (v - V[idx] >= 0) ret = max(ret, solve(idx + 1, v - V[idx]));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> S >> M;
	for (int i = 0; i < N; i++) cin >> V[i];
	int ans = solve(0, S); ans = (ans < 0) ? -1 : ans;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1495