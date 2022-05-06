#include <iostream>
#include <cmath>
using namespace std;

int N;
bool grid[31][31];
double dirPoss[4], P;
int dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };
double ans = 0;
void dfs(int y, int x, int l, double poss)
{
	if (l == N)
	{
		ans += poss;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (grid[ny][nx]) continue;
		grid[ny][nx] = true;
		dfs(ny, nx, l + 1, poss * dirPoss[i]);
		grid[ny][nx] = false;
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		cin >> P;
		dirPoss[i] = (P / (double)100);
	}
	grid[15][15] = true;
	dfs(15, 15, 0, 1.0);
	cout << fixed;
	cout.precision(20);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1405