#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1000000000;
int dp[10001][200], N, M, A;
bool S[10001];
int solve(int idx, int x)
{
	if (idx == N) return 0;
	int& ret = dp[idx][x];
	if (ret >= 0) return ret;
	ret = INF;
	if (idx + x <= N && !S[idx + x]) ret = min(ret, solve(idx + x, x) + 1);
	if (idx + x + 1 <= N && !S[idx + x + 1]) ret = min(ret, solve(idx + x + 1, x + 1) + 1);
	if (x > 1 && idx + x - 1 <= N && !S[idx + x - 1]) ret = min(ret, solve(idx + x - 1, x - 1) + 1);
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp)); memset(S, false, sizeof(S));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A;
		S[A] = true;
	}
	int ans = (S[2]) ? -1 : solve(2, 1) + 1;
	if (ans >= INF) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2253