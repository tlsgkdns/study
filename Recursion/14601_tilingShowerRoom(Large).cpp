#include <iostream>

using namespace std;
int K, X, Y, ans[260][260], cnt = 1;
void solve(int sy, int sx, int ey, int ex, int hy, int hx)
{
	int L = (ey - sy) / 2;
	if (L < 1) return;
	int cy = sy + L, cx = sx + L;
	if (hy < cy && hx < cx)
	{
		ans[cy][cx] = cnt;
		ans[cy - 1][cx] = cnt;
		ans[cy][cx - 1] = cnt;
		++cnt;
		solve(sy, sx, cy, cx, hy, hx);
		solve(sy, cx, cy, ex, cy - 1, cx);
		solve(cy, sx, ey, cx, cy, cx - 1);
		solve(cy, cx, ey, ex, cy, cx);
	}
	else if (hy < cy)
	{
		ans[cy][cx] = cnt;
		ans[cy - 1][cx - 1] = cnt;
		ans[cy][cx - 1] = cnt;
		++cnt;
		solve(sy, sx, cy, cx, cy - 1, cx - 1);
		solve(sy, cx, cy, ex, hy, hx);
		solve(cy, sx, ey, cx, cy, cx - 1);
		solve(cy, cx, ey, ex, cy, cx);
	}
	else if (hx < cx)
	{
		ans[cy][cx] = cnt;
		ans[cy - 1][cx] = cnt;
		ans[cy - 1][cx - 1] = cnt;
		++cnt;
		solve(sy, sx, cy, cx, cy - 1, cx - 1);
		solve(sy, cx, cy, ex, cy - 1, cx);
		solve(cy, sx, ey, cx, hy, hx);
		solve(cy, cx, ey, ex, cy, cx);
	}
	else
	{
		ans[cy - 1][cx - 1] = cnt;
		ans[cy - 1][cx] = cnt;
		ans[cy][cx - 1] = cnt;
		++cnt;
		solve(sy, sx, cy, cx, cy - 1, cx - 1);
		solve(sy, cx, cy, ex, cy - 1, cx);
		solve(cy, sx, ey, cx, cy, cx - 1);
		solve(cy, cx, ey, ex, hy, hx);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K >> X >> Y;
	ans[Y - 1][X - 1] = -1;
	int L = (1 << K);
	solve(0, 0, L, L, Y - 1, X - 1);
	for (int i = L - 1; i >= 0; i--)
	{
		for (int j = 0; j < L; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/14601