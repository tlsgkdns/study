#include <cstring>
#include <iostream>

using namespace std;
int dp[200001], N, H[200001];

int solve(int here)
{
	if (here >= N) return 0;
	int& ret = dp[here];
	if (ret >= 0) return ret;
	ret = solve(here + H[here] + 1) + 1;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
	for (int i = 0; i < N; i++) cout << solve(i) << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/25706