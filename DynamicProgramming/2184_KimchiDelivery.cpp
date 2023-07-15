#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
vector<int> A;
int N, L, dp[1001][1001][2], X;

int solve(int l, int r, bool p)
{
	if (l == 0 && r == N) return 0;
	int& ret = dp[l][r][p];
	if (ret >= 0) return ret;
	ret = INF; int s = N - r + l;
	if (l > 0)
		ret = min(ret, solve(l - 1, r, true) + s * ((p) ? A[l] - A[l - 1] : A[r] - A[l - 1]));
	if (r < N)
		ret = min(ret, solve(l, r + 1, false) + s * ((p) ? A[r + 1] - A[l] : A[r + 1] - A[r]));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		A.push_back(X);
	}
	A.push_back(L);
	sort(A.begin(), A.end());
	int S = 0;
	while (A[S] != L) ++S;
	cout << solve(S, S, true) << '\n';
}

// https://www.acmicpc.net/problem/2184