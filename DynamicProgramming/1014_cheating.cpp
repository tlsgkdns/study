#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
int C, N, M;
using namespace std;
vector<int> ans;
bool room[11][11];
int dp[101][1 << 11];
char ch;
int solve(int pos, int nxt)
{
	if (pos < 0) return 0;
	int& ret = dp[pos][nxt];
	if (ret >= 0) return ret;
	ret = solve(pos - 1, (nxt << 1) & ((1 << (M + 1)) - 1));
	int y = pos / M, x = pos % M;
	if (!(nxt & (1 << M)) && room[y][x])
	{
		if (x == 0)
			ret = max(ret, solve(pos - 1, (((nxt << 1) & (1 << (M + 1)) - 1)) | (1 << 2)) + 1);
		else if (x == M - 1)
			ret = max(ret, solve(pos - 1, (((nxt << 1) & (1 << (M + 1)) - 1)) | (1 << M) | 1) + 1);
		else
			ret = max(ret, solve(pos - 1, (((nxt << 1) & (1 << (M + 1)) - 1)) | (1 << 2) | (1 << M) | 1) + 1);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> C;
	while (C--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				cin >> ch;
				if (ch == '.')
					room[i][j] = true;
				else
					room[i][j] = false;
			}
		ans.push_back(solve(N * M - 1, 0));
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/1014