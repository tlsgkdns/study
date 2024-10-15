#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
vector<int> adj[5001];
int N, M, H[5001], A, B, dp[5001];

int solve(int here)
{
	int& ret = dp[here];
	if (ret >= 0) return ret;
	ret = 1;
	for (int there : adj[here])
		ret = max(ret, solve(there) + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> H[i];
	while (M--)
	{
		cin >> A >> B;
		if (H[A] < H[B]) adj[A].push_back(B);
		if (H[A] > H[B]) adj[B].push_back(A);
	}
	for (int i = 1; i <= N; i++)
		cout << solve(i) << '\n';
}

// https://www.acmicpc.net/problem/14699