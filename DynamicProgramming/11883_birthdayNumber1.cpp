#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1000000007;
int N, T, dp[1000001], B[3] = { 3, 5, 8 };

int solve(int num)
{
	int& ret = dp[num];
	if (ret >= 0) return ret;
	if (num == 0) return ret = 0;
	if (num < 3) return ret = INF;
	ret = INF;
	for (int i = 0; i < 3; i++)
		if (num >= B[i])
			ret = min(ret, solve(num - B[i]) + 1);
	return ret;
}
void solve2(string& s, int num)
{
	for (int i = 0; i < 3; i++)
		if (dp[num] == dp[num - B[i]] + 1)
		{
			s.push_back(B[i] + '0');
			solve2(s, num - B[i]);
			break;
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		string ans = "";
		solve(N);
		if (dp[N] == INF)
		{
			cout << -1 << '\n';
			continue;
		}
		solve2(ans, N);
		cout << ans << '\n';
	}
}


// https://www.acmicpc.net/problem/11883