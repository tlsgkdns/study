#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int L = 1000;
int dp[1001][1001], RS[51], RI[51], P[51], N;
int solve(int S, int I)
{
	int& ret = dp[S][I];
	if (ret >= 0) return ret;
	int s = 2; ret = 0;
	for (int i = 0; i < N; i++)
	{
		if (RS[i] > S && RI[i] > I) continue;
		s += P[i];
		ret++;
	}
	s -= (S + I);
	if (s > 0)
		for (int i = 0; i <= s; i++)
			ret = max(ret, solve(min(L, S + i), min(L, I + (s - i))));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> RS[i] >> RI[i] >> P[i];
	cout << solve(1, 1) << '\n';;
}

// https://www.acmicpc.net/problem/1315