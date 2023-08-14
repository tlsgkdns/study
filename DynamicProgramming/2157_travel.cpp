#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000007;
int N, M, K, A, B, C, dp[301][301];
int adj[301][301];
int solve(int here, int cnt)
{
	if (cnt > M) return -INF;
	if (here == N) return 0;
	int& ret = dp[here][cnt];
	if (ret >= 0) return ret;
	ret = -INF;
	for (int there = here + 1; there <= N; there++)
	{
		if (adj[here][there] == 0) continue;
		ret = max(ret, solve(there, cnt + 1) + adj[here][there]);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> A >> B >> C;
		if (B < A) continue;
		adj[A][B] = max(adj[A][B], C);
	}
	cout << solve(1, 1) << '\n';
}

// https://www.acmicpc.net/problem/2157