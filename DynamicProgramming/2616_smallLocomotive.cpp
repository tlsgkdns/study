#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int train[50001], dp[50001][4], acc[50001];
int N, M;

int solve(int idx, int r)
{
	if (r == 3 || idx > N) return 0;
	int& ret = dp[idx][r];
	if (ret != -1) return ret;
	int s = acc[min(idx - 1 + M, N)] - acc[idx - 1];
	ret = max(solve(idx + M, r + 1) + s, ret);
	ret = max(solve(idx + 1, r), ret);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; i++)
	{
		cin >> train[i];
		if (i == 1) acc[i] = train[i];
		else acc[i] = acc[i - 1] + train[i];
	}
	cin >> M;
	cout << solve(1, 0) << '\n';
}

// https://www.acmicpc.net/problem/2616