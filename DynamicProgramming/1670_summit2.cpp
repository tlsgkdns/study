#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using ll = long long;
int N;
ll dp[10001];
ll solve(int r)
{
	if (r <= 2) return 1;
	ll& ret = dp[r];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = 0; i <= r - 2; i += 2)
	{
		ret += solve(i) * solve(r - i - 2);
		ret %= 987654321;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << solve(N) << '\n';
}

// https://www.acmicpc.net/problem/1670