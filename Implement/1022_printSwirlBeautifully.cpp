#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int R1, R2, C1, C2, m = 0, ans[51][5], D[51][5];
int getDigit(int num)
{
	int cnt = 0;
	while (num > 0)
	{
		num /= 10;
		++cnt;
	}
	return cnt;
}
int getNum(int r, int c)
{
	int num = 1;
	for (int i = 0, s = (r < 0) ? 3 : 7; i < abs(r); i++)
	{
		num += s;
		s += 8;
	}
	if (c < 0)
	{
		if (abs(r) >= -c) num += (r < 0) ? -c : c;
		else
		{
			num -= r;
			int s = abs(r) * 8 + 5;
			for (int i = 0; i < abs(c) - abs(r); i++)
			{
				num += s;
				s += 8;
			}
		}
	}
	if (c > 0)
	{
		if (abs(r) >= c) num += (r < 0) ? -c : c;
		else
		{
			if (r > 0) ++r;
			num += r;
			int s = abs(r) * 8 + 1;
			for (int i = 0; i < abs(c) - abs(r); i++)
			{
				num += s;
				s += 8;
			}
		}
	}
	return num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R1 >> C1 >> R2 >> C2;
	for (int r = R1; r <= R2; r++)
	{
		for (int c = C1; c <= C2; c++)
		{
			ans[r - R1][c - C1] = getNum(r, c);
			D[r - R1][c - C1] = getDigit(ans[r - R1][c - C1]);
			m = max(D[r - R1][c - C1], m);
		}
	}
	for (int i = 0; i <= R2 - R1; i++)
	{
		for (int j = 0; j <= C2 - C1; j++)
		{
			for (int c = 0; c < m - D[i][j]; c++) cout << " ";
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/1022