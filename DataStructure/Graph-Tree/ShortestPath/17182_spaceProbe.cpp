#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 1000000000;
int planet[10][10], adj[10][10];
int dp[1 << 10][10];
int N, K;

int solve(int route, int here)
{
	if (route == (pow(2, N) - 1)) return 0;
	int& ret = dp[route][here];
	if (ret != INF) return ret;
	for (int there = 0; there < N; there++)
	{
		if (route & (1 << there)) continue;
		int nr = route | (1 << there);
		ret = min(ret, solve(nr, there) + adj[here][there]);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < (1 << 10); i++)
		for (int j = 0; j < 10; j++)
			dp[i][j] = INF;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> adj[i][j];
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	cout << solve((1 << K), K) << '\n';
}

// https://www.acmicpc.net/problem/17182