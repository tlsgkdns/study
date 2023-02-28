#include <iostream>

using namespace std;

int N, M, K, F[2003][2003], cnt = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> F[i][j];
			cnt += F[i][j];
		}
	if (cnt == 2 * K - 1)
	{
		cout << 1 << '\n';
		int sx = -1, sy = -1, y = -1, x = -1;
		for (int i = 0; i < N; i++)
		{
			if (y >= 0 && x >= 0) break;
			for (int j = 0; j < M; j++)
			{
				if (F[i][j] == 1)
				{
					if (sx < 0)
					{
						sx = j;
						sy = i;
					}
					if (i < N - 1 && F[i + 1][j] == 1)
						x = j;
					if (j < M - 1 && F[i][j + 1] == 1)
						y = i;
				}
			}
		}
		if (y < 0) y = sy + K - 1;
		if (x < 0) x = sx + K - 1;
		cout << y + 1 << " " << x + 1 << '\n';
	}
	else if (cnt == 2 * K)
	{
		cout << 0 << '\n';
	}
	else
	{
		int sy = -1, sx = -1;
		bool hor = false;
		for (int i = 0; i < N; i++)
		{
			if (sy >= 0) break;
			for (int j = 0; j < M; j++)
			{
				if (F[i][j] == 1)
				{
					if (i < N - 1 && F[i + 1][j] == 1)
					{
						sy = i;
						sx = j;
						break;
					}
					if (j < M - 1 && F[i][j + 1] == 1)
					{
						sy = i;
						sx = j;
						hor = true;
						break;
					}
				}
			}
		}
		cout << 2 * K - cnt << '\n';
		if (hor)
			for (int x = sx + cnt - K; x < sx + K; x++)
				cout << sy + 1 << " " << x + 1 << '\n';
		else
			for (int y = sy + cnt - K; y < sy + K; y++)
				cout << y + 1 << " " << sx + 1 << '\n';
	}
}

// https://www.acmicpc.net/problem/25565