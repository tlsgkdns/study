#include <iostream>
#include <vector>
using namespace std;

int N, M, s;
vector<bool> seat;
vector<vector<int>> dp;
int solve(int idx, bool dif)
{
	if (idx == N)
	{
		if (!dif) return 1;
		return 0;
	}
	int& ret = dp[idx][dif];
	if (ret != -1) return ret;
	if (dif)
	{
		if (seat[idx]) ret = 0;
		else ret = solve(idx + 1, false);
	}
	else
	{
		if (seat[idx]) ret = solve(idx + 1, false);
		else ret = solve(idx + 1, true) + solve(idx + 1, false);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);  cin.tie(NULL);
	cin >> N;
	cin >> M;
	seat.resize(N, false);
	dp.resize(N, vector<int>(2, -1));
	for (int i = 0; i < M; i++)
	{
		cin >> s;
		seat[s - 1] = true;
	}
	cout << solve(0, false) << '\n';
}
// https://www.acmicpc.net/problem/2302