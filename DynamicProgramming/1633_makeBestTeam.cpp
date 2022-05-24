#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int black[1001], white[1001];
int dp[1001][16][16], N = 0;
const int INF = -1000000000, MAX = 15;
int solve(int idx, int w, int b)
{
	if (w == MAX && b == MAX) return 0;
	if (idx == N) return INF;
	int& ret = dp[idx][w][b];
	if (ret != -1) return ret;
	if (w < MAX) ret = max(ret, solve(idx + 1, w + 1, b) + white[idx]);
	if (b < MAX) ret = max(ret, solve(idx + 1, w, b + 1) + black[idx]);
	ret = max(ret, solve(idx + 1, w, b));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	while (true)
	{
		cin >> white[N] >> black[N];
		if (cin.eof()) break;
		N++;
	}
	cout << solve(0, 0, 0) << '\n';
}

// https://www.acmicpc.net/problem/1633