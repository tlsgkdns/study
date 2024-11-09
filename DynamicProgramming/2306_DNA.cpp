#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1000000007;
int dp[501][501];
string D;

int solve(int l, int r)
{
	if (l > r) return 0;
	int& ret = dp[l][r];
	if (ret >= 0) return ret;
	ret = max(ret, solve(l, r - 1));
	ret = max(ret, solve(l + 1, r));
	if (D[l] == 'a' && D[r] == 't') ret = max(ret, solve(l + 1, r - 1) + 2);
	if (D[l] == 'g' && D[r] == 'c')
		ret = max(ret, solve(l + 1, r - 1) + 2);
	for (int i = l + 1; i + 1 < r; i++)
		ret = max(ret, solve(l, i) + solve(i + 1, r));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> D;
	cout << max(0, solve(0, D.size() - 1)) << '\n';
}

// https://www.acmicpc.net/problem/2306