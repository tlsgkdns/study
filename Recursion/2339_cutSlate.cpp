#include <iostream>
#include <cstring>
using namespace std;
int board[21][21], N;
int solve(int ly, int lx, int ry, int rx, bool hor)
{
	int pureCnt = 0, ret = 0, impureCnt = 0;
	bool PH[21], PV[21];
	memset(PH, false, sizeof(PH)); memset(PV, false, sizeof(PV));
	for (int y = ly; y <= ry; y++)
		for (int x = lx; x <= rx; x++)
		{
			if (board[y][x] == 2)
			{
				++pureCnt;
				PH[x] = true;
				PV[y] = true;
			}
			if (board[y][x] == 1)
				++impureCnt;
		}
	if (impureCnt == 0 && pureCnt == 1) return 1;
	if (pureCnt == 0) return 0;
	if (hor)
	{
		for (int y = ly; y <= ry; y++)
			for (int x = lx + 1; x < rx; x++)
			{
				if (board[y][x] != 1 || PH[x]) continue;
				ret += solve(ly, lx, ry, x - 1, !hor) * solve(ly, x + 1, ry, rx, !hor);
			}
	}
	else
	{
		for (int y = ly + 1; y < ry; y++)
		{
			if (PV[y]) continue;
			for (int x = lx; x <= rx; x++)
			{
				if (board[y][x] != 1) continue;
				ret += solve(ly, lx, y - 1, rx, !hor) * solve(y + 1, lx, ry, rx, !hor);
			}
		}

	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	int ans = solve(0, 0, N - 1, N - 1, false) + solve(0, 0, N - 1, N - 1, true);
	if (ans == 0) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2339