#include <iostream>

using namespace std;
using ll = long long;
int N, L;
ll I, dp[33][33];
string ans = "";


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> I;
	dp[0][0] = 1;
	for (int i = 1; i < 33; i++)
	{
		dp[i][i] = 1;
		dp[i][0] = 1;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	while (N > 0)
	{
		if (L == 0)
		{
			while (N-- > 0) ans.push_back('0');
			break;
		}
		ll s = 0;
		for (int i = 0; i <= L; i++)
			s += dp[N - 1][i];
		if (s >= I)
		{
			ans.push_back('0');
		}
		else
		{
			ans.push_back('1');
			--L;
			I -= s;
		}
		--N;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2248