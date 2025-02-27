#include <iostream>

using namespace std;

int C, y, i = 3;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (i--)
	{
		int c = 4, C = 0;
		while (c--)
		{
			cin >> y;
			C += (y == 0);
		}
		char ans = ' ';
		switch (C)
		{
		case 0:
			ans = 'E';
			break;
		case 1:
			ans = 'A';
			break;
		case 2:
			ans = 'B';
			break;
		case 3:
			ans = 'C';
			break;
		default:
			ans = 'D';
			break;
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/2490