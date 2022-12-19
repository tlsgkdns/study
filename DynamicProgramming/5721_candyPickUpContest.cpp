#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int M, N, ans = 0, dp[100001][2], C[100001];
int solve(int idx, bool p)
{
	if (idx >= M * N) return 0;
	int& ret = dp[idx][p];
	if (ret >= 0) return ret;
	int x = idx % N, y = idx / N;
	if (x == N - 2)
		ret = max(solve(idx + 1, p), solve(idx + N + 2, false) + C[idx]);
	else if (x == N - 1)
	{
		if (p) ret = solve(idx + N + 1, false) + C[idx];
		else ret = max(solve(idx + N + 1, false) + C[idx], solve(idx + 1, false));
	}
	else
		ret = max(solve(idx + 1, p), solve(idx + 2, true) + C[idx]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		memset(dp, -1, sizeof(dp));
		cin >> M >> N;
		if (M == 0 && N == 0) break;
		for (int i = 0; i < M * N; i++) cin >> C[i];
		cout << solve(0, false) << '\n';
	}

}

// https://www.acmicpc.net/problem/5721