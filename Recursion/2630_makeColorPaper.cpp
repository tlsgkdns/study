#include <iostream>

using namespace std;

int paper[129][129];
int N, W = 0, B = 0;
void solve(int X1, int Y1, int X2, int Y2)
{
	W, B;
	int s = paper[Y1][X1];
	bool f = false;
	for (int y = Y1; y <= Y2; y++)
		for (int x = X1; x <= X2; x++)
			if (s != paper[y][x])
			{
				f = true;
				break;
			}
	if (f)
	{
		int hx = (X1 + X2) / 2;
		int hy = (Y1 + Y2) / 2;
		solve(X1, Y1, hx, hy);
		solve(hx + 1, Y1, X2, hy);
		solve(X1, hy + 1, hx, Y2);
		solve(hx + 1, hy + 1, X2, Y2);
	}
	else
	{
		if (s) B++;
		else W++;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];
	solve(0, 0, N - 1, N - 1);
	cout << W << '\n' << B << '\n';
}

// https://www.acmicpc.net/problem/2630