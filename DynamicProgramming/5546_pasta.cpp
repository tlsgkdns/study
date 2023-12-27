#include <iostream>
#include <cstring>

using namespace std;

int N, K, A, B, dp[101][4][4], P[101];

int solve(int idx, int prv, int cnt)
{
	if (idx >= N) return 1;
	int& ret = dp[idx][prv][cnt];
	if (ret >= 0) return ret;
	if (P[idx] >= 0)
	{
		if (prv == P[idx])
		{
			if (cnt >= 2) return ret = 0;
			return ret = solve(idx + 1, prv, cnt + 1);
		}
		return ret = solve(idx + 1, P[idx], 1);
	}
	ret = 0;
	for (int i = 1; i <= 3; i++)
	{
		if (prv == i)
		{
			if (cnt >= 2) continue;
			ret += solve(idx + 1, prv, cnt + 1);
			ret %= 10000;
		}
		else
		{
			ret += solve(idx + 1, i, 1);
			ret %= 10000;
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	memset(P, -1, sizeof(P));
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> A >> B;
		P[A - 1] = B;
	}
	cout << solve(0, 0, 0) << '\n';
}

// https://www.acmicpc.net/problem/5546