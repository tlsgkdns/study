#include <iostream>
#include <queue>

using namespace std;

int N, M, ans = 0, t = 0;
int G[101][101];

void solve(int y, int x)
{
	for (int i = y; i < N; i++)
		for (int j = x; j < M; j++)
			if (G[i][j] == 1)
			{
				G[i][j] = 0;
				--t;
				solve(i, j);
				return;
			}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> G[i][j];
			t += G[i][j];
		}
	while (t > 0)
	{
		if (G[0][0] == 1)
		{
			G[0][0] = 0;
			--t;
		}
		solve(0, 0);
		++ans;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1736