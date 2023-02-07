#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[1001][162], src[1001], dst[1001], N;
const int INF = 1000000001;
int solve(int idx, int s)
{
	if (idx == N) return 0;
	int& ret = dp[idx][s + 80];
	if (ret >= 0) return ret;
	ret = INF;
	int cost = dst[idx] - (src[idx] + s), ch = cost + s;
	if ((s < 0 && ch > 0) || (s > 0 && ch < 0))
		ret = min(ret, solve(idx + 1, ch) + abs(ch));
	else
		for (int i = 0; i <= max(abs(s), abs(ch)); i++)
		{
			if (ch < 0)
				ret = min(ret, solve(idx + 1, -i) + abs(cost));
			else
				ret = min(ret, solve(idx + 1, i) + abs(cost));
		}

	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> src[i];
	for (int i = 0; i < N; i++) cin >> dst[i];
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/2879