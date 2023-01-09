#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int N, dp[100001][2][2];

const int INF = -1000000001;
int solve(int idx, bool era, bool sel)
{
	if (idx == N)
	{
		if (!sel) return INF;
		return 0;
	}
	int& ret = dp[idx][era][sel];
	if (ret != INF) return ret;
	if (!sel) ret = max(ret, solve(idx + 1, era, sel));
	ret = max(ret, solve(idx + 1, era, true) + arr[idx]);
	if (sel) ret = max(ret, 0);
	if (sel && !era) ret = max(ret, solve(idx + 1, true, sel));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 100001; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = INF;
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	cout << solve(0, false, false) << '\n';
}

// https://www.acmicpc.net/problem/13398