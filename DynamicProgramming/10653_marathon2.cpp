#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
vector<pii> points;
const int INF = 1000000000;
int N, K, X, Y;
int dp[501][501];
int getDist(pii p1, pii p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
int solve(int idx, int pass)
{
	if (idx == N - 1) return 0;
	int& ret = dp[idx][pass];
	if (ret != INF) return ret;
	int m = min(N - 1, idx + pass + 1);
	for (int i = idx + 1; i <= m; i++)
		ret = min(solve(i, pass - (i - 1 - idx)) + getDist(points[idx], points[i]), ret);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i <= 500; i++)
		for (int j = 0; j <= 500; j++)
			dp[i][j] = INF;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		points.push_back({ X, Y });
	}
	cout << solve(0, K) << '\n';
}

// https://www.acmicpc.net/problem/10653