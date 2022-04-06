#include <iostream>
#include <cstring>
using namespace std;

string str;

const int MOD = 1000000;
int N, dp[5001];

int solve(int idx)
{
	if (idx > N) return dp[idx] = 0;
	if (idx == N) return dp[idx] = 1;
	if (str[idx] == '0') return 0;
	if (dp[idx] != -1) return dp[idx];
	if (str[idx] == '1') return dp[idx] = (solve(idx + 1) + solve(idx + 2)) % 1000000;
	if (idx < N - 1 && str[idx] == '2' && str[idx + 1] <= '6') return dp[idx] = (solve(idx + 1) + solve(idx + 2)) % 1000000;
	return dp[idx] = solve(idx + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> str;
	N = (int)str.size();
	cout << solve(0) << '\n';
}

// https://www.acmicpc.net/problem/2011