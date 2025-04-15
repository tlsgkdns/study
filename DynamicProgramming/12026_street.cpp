#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int N, dp[1001];
const int INF = 1e9 + 7;
string P;

int solve(int here)
{
	if (here == N - 1) return 0;
	int& ret = dp[here];
	if (ret >= 0) return ret;
	ret = INF;
	char nxt = ' ';
	if (P[here] == 'B') nxt = 'O';
	else if (P[here] == 'O') nxt = 'J';
	else nxt = 'B';
	for (int there = here + 1; there < N; there++)
		if (nxt == P[there])
			ret = min(ret, solve(there) + (int)pow(there - here, 2));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cin >> P;
	int ans = solve(0);
	if (ans >= INF) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/12026