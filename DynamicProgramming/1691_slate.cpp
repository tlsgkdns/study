#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1000000007;

int N, H, W, dp[601][601], A[201], B[201];

int solve(int h, int w)
{
	int& ret = dp[h][w];
	if (ret >= 0) return ret;
	ret = h * w;
	for (int i = 0; i < N; i++)
	{
		if (A[i] == w && B[i] == h)
		{
			ret = 0;
			return ret;
		}
	}
	for (int i = 1; i <= (w / 2); i++)
		ret = min(ret, solve(h, w - i) + solve(h, i));
	for (int i = 1; i <= (h / 2); i++)
		ret = min(ret, solve(h - i, w) + solve(i, w));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> W >> H;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
	cout << solve(H, W) << '\n';
}

// https://www.acmicpc.net/problem/1691