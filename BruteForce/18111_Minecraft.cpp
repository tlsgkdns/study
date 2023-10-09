#include <iostream>
#include <algorithm>
using namespace std;
int N, M, B, G[501][501], ans1 = 1000000007, ans2 = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> G[i][j];
	for (int h = 0; h <= 256; h++)
	{
		int s = 0, b = B, t = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (G[i][j] > h)
				{
					b += (G[i][j] - h);
					t += (G[i][j] - h) * 2;
				}
		bool f = true;
		for (int i = 0; (i < N) && f; i++)
			for (int j = 0; j < M; j++)
			{
				if (G[i][j] > h) continue;
				if (b < h - G[i][j])
				{
					f = false;
					break;
				}
				t += (h - G[i][j]);
				b -= (h - G[i][j]);
			}
		if (!f) continue;
		if (ans1 >= t)
		{
			ans1 = t;
			ans2 = h;
		}
	}
	cout << ans1 << " " << ans2 << '\n';
}

// https://www.acmicpc.net/problem/18111