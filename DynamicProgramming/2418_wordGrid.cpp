#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
char B[201][201];
int H, W, L;
string str;
ll dp[201][201][101];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < H && x < W;
}
ll solve(int r, int c, int l)
{
	if (l == L) return 1;
	ll& ret = dp[r][c][l];
	if (ret >= 0) return ret;
	ret = 0;
	for (int d = 0; d < 8; d++)
	{
		int ny = r + dy[d];
		int nx = c + dx[d];
		if (!inRange(ny, nx) || B[ny][nx] != str[l]) continue;
		ret += solve(ny, nx, l + 1);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> H >> W >> L;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> B[i][j];
	cin >> str;
	ll ans = 0;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			if (str[0] == B[i][j])
				ans += solve(i, j, 1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2418