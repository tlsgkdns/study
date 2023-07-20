#include <iostream>
#include <cstring>
using namespace std;

string num;
int dp[42];
int solve(int idx)
{
	if (num.size() == idx) return 1;
	if (num[idx] == '0') return 0;
	int& ret = dp[idx];
	if (ret >= 0) return ret;
	ret = 0;
	if (idx < num.size() - 1 && ((num[idx] - '0') * 10 + (num[idx + 1] - '0')) <= 34)
		ret += solve(idx + 2);
	ret += solve(idx + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> num;
	cout << solve(0) << '\n';
}

// https://www.acmicpc.net/problem/2591