#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;
int digit[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };
string str;
ll S = 0;
int N = 0;
ll dp[16][120][2][2];
const ll INF = 1e17;
ll solve(int idx, int cnt, bool up, bool same)
{
	if (cnt > S) return INF;
	if (idx < 0)
	{
		if (cnt == S)
		{
			if (same) return pow(10, N);
			return 0;
		}
		return INF;
	}
	ll& ret = dp[idx][cnt][up][same];
	if (ret >= 0) return ret;
	ret = INF;
	int from = (str[idx] - '0' + up) % 10;
	for (int to = 0; to < 10; to++)
	{
		if (from <= to)
			ret = min(ret, (solve(idx - 1, cnt + digit[to], (from == 0 && up) ? true : false, (from == to) && same) + ((to - from) * (ll)pow(10, N - idx - 1))));
		else
			ret = min(ret, (solve(idx - 1, cnt + digit[to], true, (from == to) && same) + ((10 + to - from) * (ll)pow(10, N - idx - 1))));
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> str; N = (int)str.size();
	for (int i = 0; i < N; i++) S += digit[str[i] - '0'];
	cout << solve(N - 1, 0, false, true) << '\n';
}

// https://www.acmicpc.net/problem/1020