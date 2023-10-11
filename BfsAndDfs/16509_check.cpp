#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int R1, C1, R2, C2, v[10][9], ans = -1;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y <= 9 && x <= 8;
}
bool eq(int y, int x)
{
	return y == R2 && x == C2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> R1 >> C1 >> R2 >> C2;
	queue<pair<int, int>> q;
	q.push({ R1, C1 });
	v[R1][C1] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (eq(y, x))
		{
			ans = v[y][x];
			break;
		}
		if (inRange(y - 1, x) && !eq(y - 1, x))
		{
			if (inRange(y - 3, x - 2) && inRange(y - 2, x - 1) && !eq(y - 2, x - 1) && v[y - 3][x - 2] < 0)
			{
				v[y - 3][x - 2] = v[y][x] + 1;
				q.push({ y - 3, x - 2 });
			}
			if (inRange(y - 3, x + 2) && inRange(y - 2, x + 1) && !eq(y - 2, x + 1) && v[y - 3][x + 2] < 0)
			{
				v[y - 3][x + 2] = v[y][x] + 1;
				q.push({ y - 3, x + 2 });
			}
		}
		if (inRange(y + 1, x) && !eq(y + 1, x))
		{
			if (inRange(y + 3, x - 2) && inRange(y + 2, x - 1) && !eq(y + 2, x - 1) && v[y + 3][x - 2] < 0)
			{
				v[y + 3][x - 2] = v[y][x] + 1;
				q.push({ y + 3, x - 2 });
			}
			if (inRange(y + 3, x + 2) && inRange(y + 2, x + 1) && !eq(y + 2, x + 1) && v[y + 3][x + 2] < 0)
			{
				v[y + 3][x + 2] = v[y][x] + 1;
				q.push({ y + 3, x + 2 });
			}
		}
		if (inRange(y, x - 1) && !eq(y, x - 1))
		{
			if (inRange(y - 2, x - 3) && inRange(y - 1, x - 2) && !eq(y - 1, x - 2) && v[y - 2][x - 3] < 0)
			{
				v[y - 2][x - 3] = v[y][x] + 1;
				q.push({ y - 2, x - 3 });
			}
			if (inRange(y + 2, x - 3) && inRange(y + 1, x - 2) && !eq(y + 1, x - 2) && v[y + 2][x - 3] < 0)
			{
				v[y + 2][x - 3] = v[y][x] + 1;
				q.push({ y + 2, x - 3 });
			}
		}
		if (inRange(y, x + 1) && !eq(y, x + 1))
		{
			if (inRange(y - 2, x + 3) && inRange(y - 1, x + 2) && !eq(y - 1, x + 2) && v[y - 2][x + 3] < 0)
			{
				v[y - 2][x + 3] = v[y][x] + 1;
				q.push({ y - 2, x + 3 });
			}
			if (inRange(y + 2, x + 3) && inRange(y + 1, x + 2) && !eq(y + 1, x + 2) && v[y + 2][x + 3] < 0)
			{
				v[y + 2][x + 3] = v[y][x] + 1;
				q.push({ y + 2, x + 3 });
			}
		}
	}
	cout << ans << '\n';
}

// https://solved.ac/contribute/16509