#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int N, M;
const ll INF = -100000000000000;
ll S[500003], B[500003], dp[500003][2], acc[500003];
ll solve(int idx, bool bonus)
{
	if (idx > N) return 0;
	ll& ret = dp[idx][bonus];
	if (ret > INF) return ret;
	ret = 0;
	if (bonus && idx + M - 1 <= N) ret = max(ret, solve(idx + M, true) + acc[idx + M - 1] - acc[idx - 1] + B[idx + M - 1]);
	ret = max(ret, solve(idx + 1, false) + S[idx]);
	ret = max(ret, solve(idx + 1, true) - S[idx]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	acc[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> S[i];
		acc[i] = acc[i - 1] + S[i];
		dp[i][0] = dp[i][1] = INF;
	}
	for (int i = 1; i <= N; i++) cin >> B[i];
	cout << solve(1, true) << '\n';
}

// https://www.acmicpc.net/problem/1462