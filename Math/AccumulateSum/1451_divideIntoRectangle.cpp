#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
ll N, M, R[51][51];
char ch;
ll solve(int sy, int sx, int ey, int ex, int d)
{
	if (sy > ey || sx > ex) return 0;
	if (d == 1)
	{
		return R[ey][ex] + R[sy - 1][sx - 1] - R[sy - 1][ex] - R[ey][sx - 1];
	}
	ll ret = 1;
	for (int y = sy; y <= ey; y++)
		for (int l = 1; l < d; l++)
			ret = max(ret, solve(sy, sx, y, ex, l) * solve(y + 1, sx, ey, ex, d - l));
	for (int x = sx; x <= ex; x++)
		for (int l = 1; l < d; l++)
			ret = max(ret, solve(sy, sx, ey, x, l) * solve(sy, x + 1, ey, ex, d - l));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> ch;
			R[i][j] = (ch - '0') + R[i - 1][j] + R[i][j - 1] - R[i - 1][j - 1];
		}
	cout << solve(1, 1, N, M, 3) << '\n';
}

// https://www.acmicpc.net/problem/1451