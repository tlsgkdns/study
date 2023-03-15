#include <iostream>
#include <cstring>
using namespace std;
int dp[1001];
int N;
bool solve(int n)
{
	if (n == 0) return 1;
	int& ret = dp[n];
	if (ret >= 0) return ret;
	ret = 0;
	if (n >= 1) ret = ret || !solve(n - 1);
	if (n >= 3) ret = ret || !solve(n - 3);
	if (n >= 4) ret = ret || !solve(n - 4);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	dp[1] = 1; dp[2] = 0;
	dp[3] = 1; dp[4] = 1;
	string ans = (solve(N) ? "SK" : "CY");
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/9657