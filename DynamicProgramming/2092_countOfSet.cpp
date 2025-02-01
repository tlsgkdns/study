#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int MOD = 1000000;
vector<int> n;
int T, A, S, B, dp[4001][4001], arr[4001], cnt[201], ans = 0;

int solve(int idx, int s)
{
	int& ret = dp[idx][s];
	if (idx == n.size()) return ret = (s == 0);
	if (ret >= 0) return ret;
	ret = 0;
	for (int c = 0; c <= min(s, cnt[n[idx]]); c++)
	{
		ret += solve(idx + 1, s - c);
		ret %= MOD;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> T >> A >> S >> B;
	for (int i = 0; i < A; i++)
	{
		cin >> arr[i];
		if (cnt[arr[i]]++ == 0)
			n.push_back(arr[i]);
	}
	for (int a = 0; a <= A; a++)
		solve(0, a);
	solve(0, 0);
	for (int i = S; i <= B; i++)
	{
		ans += dp[0][i];
		ans %= MOD;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2092