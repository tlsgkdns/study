#include <iostream>
using namespace std;

int N;
double A[10001], dp[10001][2];

double solve(int idx, bool b)
{
	if (idx == N)
	{
		if (!b) return 0.0;
		return 1.0;
	}
	double& ret = dp[idx][b];
	if (ret >= 0) return ret;
	if (b)
		ret = max(1.0, solve(idx + 1, true) * A[idx]);
	else
		ret = max(solve(idx + 1, false), solve(idx + 1, true) * A[idx]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		dp[i][0] = dp[i][1] = -1.0;
	}
	cout << fixed; cout.precision(3);
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/2670