#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> ans;
int dp[10001][4], T, N;
int solve(int num, int plus)
{
	if (num < 0) return 0;
	if (num == 0) return 1;
	int& ret = dp[num][plus];
	if (ret != -1) return ret;
	ret = 0;
	for (int n = plus; n <= 3; n++)
		ret += solve(num - n, n);
	return ret;
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
		ans.push_back(solve(N, 1));
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/15989