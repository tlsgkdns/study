#include <iostream>
#include <functional>
#include <cstring>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using cmpFunc = function<bool(pii, pii)>;
pii P[3001];
int dp[3001][4], N, ans = -1;
cmpFunc f1 = [](pii p1, pii p2) {return p1.first < p2.first && p1.second < p2.second; };
cmpFunc f2 = [](pii p1, pii p2) {return p1.first < p2.first && p1.second > p2.second; };
cmpFunc f3 = [](pii p1, pii p2) {return p1.first > p2.first && p1.second < p2.second; };
cmpFunc f4 = [](pii p1, pii p2) {return p1.first > p2.first && p1.second > p2.second; };

int solve(const cmpFunc& func, int idx, int dpIdx)
{
	int& ret = dp[idx][dpIdx];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = 0; i < N; i++)
	{
		if (idx == i) continue;
		if (func(P[idx], P[i]))
			ret = max(ret, solve(func, i, dpIdx) + 1);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
	for (int i = 0; i < N; i++) solve(f1, i, 0);
	for (int i = 0; i < N; i++) solve(f2, i, 1);
	for (int i = 0; i < N; i++) solve(f3, i, 2);
	for (int i = 0; i < N; i++) solve(f4, i, 3);
	for (int i = 0; i < N; i++)
	{
		if (dp[i][0] == 0 || dp[i][1] == 0 || dp[i][2] == 0 || dp[i][3] == 0) continue;
		ans = max(ans, dp[i][0] + dp[i][1] + dp[i][2] + dp[i][3] + 1);
	}
	if (ans >= 0) ans = N - ans;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/25543