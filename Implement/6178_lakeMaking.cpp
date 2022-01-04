#include <iostream>
#include <algorithm>
using namespace std;

int pasture[101][101];

int R, C, E, N, Rs, Cs, Ds;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> E >> N;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> pasture[i][j];
	for (int i = 0; i < N; i++)
	{
		cin >> Rs >> Cs >> Ds;
		int m = -1;
		for (int r = Rs; r <= Rs + 2; r++)
			for (int c = Cs; c <= Cs + 2; c++)
				m = max(pasture[r][c], m);
		m = max(0, m - Ds);
		for (int r = Rs; r <= Rs + 2; r++)
			for (int c = Cs; c <= Cs + 2; c++)
			{
				if (m > pasture[r][c]) continue;
				pasture[r][c] = m;
			}
	}
	int ans = 0;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (pasture[i][j] < E)
				ans += (E - pasture[i][j]);
	ans = ans * 72 * 72;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/6178