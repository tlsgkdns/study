#include <iostream>

using namespace std;

int R, C, K, cnt = 1, ansY = -1, ansX = -1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> C >> R;
	cin >> K;
	if (R * C < K) cout << 0 << '\n';
	else
	{
		int sy = 1, sx = 1, ey = R, ex = C;
		while (sy <= ey && sx <= ex)
		{
			for (int y = sy; y < ey; y++, cnt++)
				if (cnt == K)
				{
					ansY = y;
					ansX = sx;
				}
			for (int x = sx; x < ex; x++, cnt++)
				if (cnt == K)
				{
					ansY = ey;
					ansX = x;
				}
			for (int y = ey; y > sy; y--, cnt++)
				if (cnt == K)
				{
					ansY = y;
					ansX = ex;
				}
			for (int x = ex; x > sx; x--, cnt++)
				if (cnt == K)
				{
					ansY = sy;
					ansX = x;
				}
			sy++; sx++;
			ey--; ex--;
		}
		cout << ansX << " " << ansY << '\n';
	}
}

// https://www.acmicpc.net/problem/10157