#include <iostream>

using namespace std;

int dp[10001], M, idx = 0;
string str = " Messi Gimossi";
char ans = ' ';
void solve(int n)
{
	int i = 0;
	while (dp[i] < n) ++i;
	if (i <= 1)
	{
		ans = str[n];
		return;
	}
	solve(n - dp[i - 1] - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M;
	dp[0] = 5;
	dp[1] = 13;
	while (dp[idx] + dp[idx + 1] + 1 < M)
	{
		dp[idx + 2] = dp[idx] + dp[idx + 1] + 1;
		++idx;
	}
	dp[idx + 2] = dp[idx] + dp[idx + 1] + 1;
	solve(M);
	if (ans == ' ') cout << "Messi Messi Gimossi\n";
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17297