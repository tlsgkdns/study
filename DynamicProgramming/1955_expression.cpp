#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N, dp[10001];

int solve(int num)
{
	if (num <= 1) return num;
	int& ret = dp[num];
	if (ret >= 0) return ret;
	ret = 100001;
	for (int n = 1; n <= (num / 2); n++)
		ret = min(ret, solve(num - n) + solve(n));
	for (int n = 1; n <= sqrt(num); n++)
		if (num % n == 0)
			ret = min(ret, solve(num / n) + solve(n));
	int n = 2, f = 3;
	while (n <= num)
	{
		if (num % n == 0) ret = min(ret, solve(num / n) + solve(f - 1));
		ret = min(ret, solve(num - n) + solve(f - 1));
		n *= f++;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << solve(N) << '\n';
}

// https://www.acmicpc.net/problem/1955