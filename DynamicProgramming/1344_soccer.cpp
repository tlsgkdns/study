#include <iostream>
#include <cstring>

using namespace std;

double dp[19][19][19], A, B;
int prime[7] = { 2, 3, 5, 7, 11, 13, 17 };
double solve(int a, int b, int t)
{
	if (t == 18)
	{
		for (int i = 0; i < 7; i++)
			if (a == prime[i] || b == prime[i])
				return 1;
		return 0;
	}
	double& ret = dp[a][b][t];
	if (ret >= 0) return ret;
	ret = 0;
	ret += solve(a + 1, b, t + 1) * A * (1 - B);
	ret += solve(a, b + 1, t + 1) * B * (1 - A);
	ret += solve(a, b, t + 1) * (1 - A) * (1 - B);
	ret += solve(a + 1, b + 1, t + 1) * A * B;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> A >> B;
	A /= 100; B /= 100;
	cout << fixed;
	cout.precision(7);
	cout << solve(0, 0, 0) << '\n';
}

// https://www.acmicpc.net/problem/1344