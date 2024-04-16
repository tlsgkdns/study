#include <iostream>
#include <algorithm>
using namespace std;

int T, y = 0, x = 0, sy = 0, sx = 0, ey = 0, ex = 0, d = 0;
string C;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
void setPos()
{
	sy = min(sy, y);
	sx = min(sx, x);
	ey = max(ey, y);
	ex = max(ex, x);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		y = 0; x = 0; sy = 0; sx = 0; ey = 0; ex = 0; d = 0;
		cin >> C;
		for (int idx = 0; idx < C.size(); idx++)
		{
			switch (C[idx])
			{
			case 'F':
				y += dy[d];
				x += dx[d];
				setPos();
				break;
			case 'B':
				y += dy[(d + 2) % 4];
				x += dx[(d + 2) % 4];
				setPos();
				break;
			case 'L':
				d = (d + 3) % 4;
				break;
			case 'R':
				d = (d + 1) % 4;
				break;
			default:
				break;
			}
		}
		cout << (ey - sy) * (ex - sx) << '\n';
	}
}

// https://www.acmicpc.net/problem/8911