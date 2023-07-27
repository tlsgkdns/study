#include <iostream>
#include <cstring>

using namespace std;
int dp[1001][1001], A, B;

int solve(int a, int b)
{
	if (a < 3 && b < 3) return (a + b) % 2;
	int& ret = dp[a][b];
	if (ret >= 0) return ret;
	ret = 0;
	if (a >= 3 && b > 0) ret = ret || !(solve(a - 3, b - 1) > 0);
	if (a > 0 && b >= 3) ret = ret || !(solve(a - 1, b - 3) > 0);
	if (a > 0) ret = ret || !(solve(a - 1, b) > 0);
	if (b > 0) ret = ret || !(solve(a, b - 1) > 0);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> A >> B;
	string ans = solve(A, B) > 0 ? "Alice" : "Bob";
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15877