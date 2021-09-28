#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int N;
vector<vector<int>> paint;
vector<vector<vector<int>>> dp;
int solve(int idx, int prevColor, int firstColor)
{
	if (idx == N) return 0;
	int& ret = dp[idx][prevColor][firstColor];
	if (ret != INF) return ret;
	for (int clr = 0; clr < 3; clr++)
	{
		if (clr == prevColor) continue;
		if (idx == N - 1 && clr == firstColor) continue;
		ret = min(ret, solve(idx + 1, clr, firstColor) + paint[idx][clr]);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	paint.resize(N, vector<int>(3));
	dp.resize(N, vector<vector<int>>(3, vector<int>(3, INF)));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> paint[i][j];
	int ans = INF;
	for (int c = 0; c < 3; c++)
		ans = min(solve(1, c, c) + paint[0][c], ans);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17404