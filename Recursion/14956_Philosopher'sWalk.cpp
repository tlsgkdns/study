#include <iostream>
#include <cmath>
using namespace std;

int N, M;
void solve(int sy, int sx, int ey, int ex, int shape, int r)
{
	if (sy == ey && sx == ex)
	{
		cout << sx << " " << sy << '\n';
		return;
	}
	int L = (ey - sy) + 1;
	int s = L * L; int n = (s / 4);
	int num = (r - 1) / n; L /= 2;
	if (shape == 0)
	{
		if (num == 0)
			solve(sy, sx, ey - L, ex - L, 1, r);
		else if (num == 1)
			solve(sy + L, sx, ey, ex - L, 0, r - n);
		else if (num == 2)
			solve(sy + L, sx + L, ey, ex, 0, r - 2 * n);
		else
			solve(sy, sx + L, ey - L, ex, 2, r - 3 * n);
	}
	if (shape == 1)
	{
		if (num == 0)
			solve(sy, sx, ey - L, ex - L, 0, r);
		else if (num == 1)
			solve(sy, sx + L, ey - L, ex, 1, r - n);
		else if (num == 2)
			solve(sy + L, sx + L, ey, ex, 1, r - 2 * n);
		else
			solve(sy + L, sx, ey, ex - L, 3, r - 3 * n);
	}
	if (shape == 2)
	{
		if (num == 0)
			solve(sy + L, sx + L, ey, ex, 3, r);
		else if (num == 1)
			solve(sy + L, sx, ey, ex - L, 2, r - n);
		else if (num == 2)
			solve(sy, sx, ey - L, ex - L, 2, r - 2 * n);
		else
			solve(sy, sx + L, ey - L, ex, 0, r - 3 * n);
	}
	if (shape == 3)
	{
		if (num == 0)
			solve(sy + L, sx + L, ey, ex, 2, r);
		else if (num == 1)
			solve(sy, sx + L, ey - L, ex, 3, r - n);
		else if (num == 2)
			solve(sy, sx, ey - L, ex - L, 3, r - 2 * n);
		else
			solve(sy + L, sx, ey, ex - L, 1, r - 3 * n);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	solve(1, 1, N, N, 0, M);
}

// https://www.acmicpc.net/problem/14956