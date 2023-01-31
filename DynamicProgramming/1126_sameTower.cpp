#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int N, H[51], dp[51][500001], ans = -1;
const int NINF = -1000000001;
int solve(int idx, int h)
{
	if (idx == N)
	{
		if (h == 0) return 0;
		else return NINF;
	}
	int& ret = dp[idx][abs(h)];
	if (ret != NINF) return ret;
	ret = max(ret, solve(idx + 1, h));
	ret = max(ret, solve(idx + 1, h + H[idx]) + H[idx]);
	ret = max(ret, solve(idx + 1, h - H[idx]) + H[idx]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= 500000; j++)
			dp[i][j] = NINF;
	for (int i = 0; i < N; i++) cin >> H[i];
	ans = solve(0, 0);
	if (ans == 0) ans = -1;
	else ans = abs(ans) / 2;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1126