#include <iostream>
#include <cstring>
using namespace std;

int N, L;
char ans[501][501];
void solve(int sy, int sx, int ey, int ex)
{
	if (sy > ey) return;
	for (int x = sx; x < ex; x++) ans[sy][x] = '*';
	for (int y = sy + 1; y < ey; y++) ans[y][ex - 1] = '*';
	for (int x = ex - 2; x >= sx; x--) ans[ey - 1][x] = '*';
	for (int y = ey - 2; y > sy; y--) ans[y][sx] = '*';
	solve(sy + 2, sx + 2, ey - 2, ex - 2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	L = 4 * N - 3;
	solve(0, 0, L, L);
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
			if (ans[i][j] != '*') cout << ' ';
			else cout << ans[i][j];
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/10994