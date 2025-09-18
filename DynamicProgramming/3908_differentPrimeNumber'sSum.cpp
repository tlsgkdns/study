#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int T, N, K, dp[1202][15][200];
bool P[1202];
vector<int> prime;
int solve(int n, int k, int idx)
{
	if (k == 0)
	{
		return (n == 0);
	}
	int& ret = dp[n][k][idx];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = idx; i < prime.size() && prime[i] <= n; i++)
		ret += solve(n - prime[i], k - 1, i + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	memset(P, true, sizeof(P));
	P[0] = P[1] = false;
	for (int i = 2; i <= 1200; i++)
		if (P[i])
		{
			prime.push_back(i);
			for (int j = i * i; j <= 1200; j += i)
				P[j] = false;
		}
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> K;
		cout << solve(N, K, 0) << '\n';
	}
}

// https://www.acmicpc.net/problem/3908