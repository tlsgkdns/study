#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
const int INF = 1000000007;

string O, N;
int dp[1001][1001], ans = 0;
int solve(int l, int r)
{
	if (l == O.size()) return r < N.size();
	int& ret = dp[l][r];
	if (ret >= 0) return ret;
	ret = INF;
	for (int idx = r; idx < N.size(); idx++)
		if (O[l] == N[idx])
			ret = min(ret, solve(l + 1, idx + 1) + (r != idx));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	getline(cin, O);
	getline(cin, N);
	ans = solve(0, 0);
	if (ans == INF) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1230