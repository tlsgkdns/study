#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 100000;
int N;
vector<int> arr, dp;
int solve(int pos)
{
	if (pos >= N) return INF;
	if (pos == N - 1) return dp[pos] = 0;
	if (dp[pos] != INF) return dp[pos];
	for (int i = 1; i <= arr[pos]; i++)
		dp[pos] = min(solve(pos + i) + 1, dp[pos]);
	return dp[pos];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr.resize(N); dp.resize(N, INF);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	solve(0);
	if (dp[0] >= INF) dp[0] = -1;
	cout << dp[0] << '\n';
}
// https://www.acmicpc.net/problem/11060