#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
int N;
string S, D;

int dp[102][21][21][21];

int getRot(int r)
{
	if (r >= 10) return r - 10;
	if (r < 0) return r + 10;
	return r;
}
int solve(int idx, int cur, int nxt, int afterNxt)
{
	if (idx == N) return 0;
	int& ret = dp[idx][cur + 10][nxt + 10][afterNxt + 10];
	if (ret != -1) return ret;
	ret = INF;
	int here = (S[idx] - '0' + cur + 10) % 10, there = D[idx] - '0';
	if (here == there) return ret = solve(idx + 1, nxt, afterNxt, 0);
	for (int i = 1; i <= min(3, 10 + here - there); i++)
	{
		ret = min(ret, solve(idx, getRot(cur - i), nxt, afterNxt) + 1);
		ret = min(ret, solve(idx, getRot(cur - i), getRot(nxt - i), afterNxt) + 1);
		ret = min(ret, solve(idx, getRot(cur - i), getRot(nxt - i), getRot(afterNxt - i)) + 1);
	}
	for (int i = 1; i <= min(3, there - here); i++)
	{
		ret = min(ret, solve(idx, getRot(cur + i), nxt, afterNxt) + 1);
		ret = min(ret, solve(idx, getRot(cur + i), getRot(nxt + i), afterNxt) + 1);
		ret = min(ret, solve(idx, getRot(cur + i), getRot(nxt + i), getRot(afterNxt + i)) + 1);
	}
	for (int i = 1; i <= min(3, 10 + there - here); i++)
	{
		ret = min(ret, solve(idx, getRot(cur + i), nxt, afterNxt) + 1);
		ret = min(ret, solve(idx, getRot(cur + i), getRot(nxt + i), afterNxt) + 1);
		ret = min(ret, solve(idx, getRot(cur + i), getRot(nxt + i), getRot(afterNxt + i)) + 1);
	}
	for (int i = 1; i <= min(3, here - there); i++)
	{
		ret = min(ret, solve(idx, getRot(cur - i), nxt, afterNxt) + 1);
		ret = min(ret, solve(idx, getRot(cur - i), getRot(nxt - i), afterNxt) + 1);
		ret = min(ret, solve(idx, getRot(cur - i), getRot(nxt - i), getRot(afterNxt - i)) + 1);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cin >> S;
	cin >> D;
	cout << solve(0, 0, 0, 0) << '\n';
}

// https://www.acmicpc.net/problem/1514