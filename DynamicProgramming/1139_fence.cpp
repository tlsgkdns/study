#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
double dp[(1 << 16) + 1], F[17];

double solve(int s)
{
	double& ret = dp[s];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = 0; i < N; i++)
	{
		if (s & (1 << i)) continue;
		for (int j = i + 1; j < N; j++)
		{
			if (s & (1 << j)) continue;
			for (int k = j + 1; k < N; k++)
			{
				if (s & (1 << k) || (F[i] + F[j] <= F[k])) continue;
				double p = (F[i] + F[j] + F[k]) / 2;
				double area = sqrt(p * (p - F[i]) * (p - F[j]) * (p - F[k]));
				ret = max(ret, solve(s | (1 << i) | (1 << j) | (1 << k)) + area);
			}
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)cin >> F[i];
	cout.precision(10); cout << fixed;
	cout << solve(0) << '\n';
}

// https://www.acmicpc.net/problem/1139