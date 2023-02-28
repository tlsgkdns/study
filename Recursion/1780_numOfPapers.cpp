#include <iostream>

using namespace std;

int N, ans[3];
int P[2188][2188];
void solve(int sy, int sx, int ey, int ex)
{
	int a = P[sy][sx];
	bool br = false;
	for (int y = sy; y < ey; y++)
	{
		if (br) break;
		for (int x = sx; x < ex; x++)
		{
			if (a != P[y][x])
			{
				br = true;
				break;
			}
		}
	}
	if (!br)
	{
		++ans[a + 1];
		return;
	}
	int n = (ey - sy) / 3;
	solve(sy, sx, sy + n, sx + n);
	solve(sy, sx + n, sy + n, sx + 2 * n);
	solve(sy, sx + 2 * n, sy + n, sx + 3 * n);
	solve(sy + n, sx, sy + 2 * n, sx + n);
	solve(sy + n, sx + n, sy + 2 * n, sx + 2 * n);
	solve(sy + n, sx + 2 * n, sy + 2 * n, sx + 3 * n);
	solve(sy + 2 * n, sx, sy + 3 * n, sx + n);
	solve(sy + 2 * n, sx + n, sy + 3 * n, sx + 2 * n);
	solve(sy + 2 * n, sx + 2 * n, sy + 3 * n, sx + 3 * n);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> P[i][j];
	solve(0, 0, N, N);
	for (int i = 0; i < 3; i++)
		cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/1780