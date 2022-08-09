#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[21][21][21], M, N, door[21], D1, D2;

int solve(int o1, int o2, int idx)
{
	if (idx == N) return 0;
	int& ret = dp[o1][o2][idx];
	if (ret >= 0) return ret;
	ret = min(solve(door[idx], o2, idx + 1) + abs(door[idx] - o1), solve(o1, door[idx], idx + 1) + abs(door[idx] - o2));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> M;
	cin >> D1 >> D2;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> door[i];
	cout << solve(D1, D2, 0) << '\n';
}

// https://www.acmicpc.net/problem/2666