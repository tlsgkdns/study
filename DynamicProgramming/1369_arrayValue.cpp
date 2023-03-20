#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
int dp[1001][1001], dp2[1001][1001], N, arr[1001][1001], v[1001][1001];
int cnt1[1001][1001], cnt2[1001][1001];

int solve(int y, int x)
{
	if (y == N - 1 && x == N - 1) return cnt1[y][x];
	int& ret = dp[y][x];
	if (ret >= 0) return ret;
	ret = INF;
	int s = (arr[y][x] == 0) ? INF : cnt1[y][x];
	if (y < N - 1)
		ret = min(ret, solve(y + 1, x) + s);
	if (x < N - 1)
		ret = min(ret, solve(y, x + 1) + s);
	return ret;
}
int solve2(int y, int x)
{
	if (y == N - 1 && x == N - 1) return cnt2[y][x];
	int& ret = dp2[y][x];
	if (ret >= 0) return ret;
	ret = INF;
	int s = (arr[y][x] == 0) ? INF : cnt2[y][x];
	if (y < N - 1)
		ret = min(ret, solve2(y + 1, x) + s);
	if (x < N - 1)
		ret = min(ret, solve2(y, x + 1) + s);
	return ret;
}

bool dfs(int y, int x)
{
	if (arr[y][x] == 0) return false;
	if (y == N - 1 && x == N - 1) return true;
	int& ret = v[y][x];
	if (ret >= 0) return ret;
	ret = false;
	if (y < N - 1) ret |= dfs(y + 1, x);
	if (x < N - 1) ret |= dfs(y, x + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp)); memset(dp2, -1, sizeof(dp2));
	memset(v, -1, sizeof(v));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0) continue;
			int tmp = arr[i][j];
			while (tmp % 2 == 0)
			{
				++cnt1[i][j];
				tmp /= 2;
			}
			tmp = arr[i][j];
			while (tmp % 5 == 0)
			{
				++cnt2[i][j];
				tmp /= 5;
			}
		}
	if (!dfs(0, 0)) cout << 1 << '\n';
	else
		cout << min(solve(0, 0), solve2(0, 0)) << '\n';
}

// https://www.acmicpc.net/problem/1369