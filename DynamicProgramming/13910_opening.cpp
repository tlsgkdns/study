#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000007;

int N, M, S[101], dp[10001];

int solve(int idx)
{
	int& ret = dp[idx];
	if (idx == 0) return ret = 0;
	if (ret >= 0) return ret;
	ret = INF;
	for (int i = 0; i <= M; i++)
		for (int j = i + 1; j <= M; j++)
			if (idx >= S[i] + S[j])
				ret = min(ret, solve(idx - S[i] - S[j]) + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
		cin >> S[i];
	int ans = solve(N);
	if (ans == INF) cout << -1 << '\n';
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13910