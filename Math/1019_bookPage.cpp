#include <iostream>

using namespace std;
int ans[10], n;

void calc(int num, int inc)
{
	while (num != 0)
	{
		ans[num % 10] += inc;
		num /= 10;
	}
}

int main()
{
	cin >> n;
	int a = 1, b = n, digit = 1;
	while (a != 0)
	{
		while (a != b && a % 10 != 0)
		{
			calc(a, digit);
			a++;
		}
		while (b != a && b % 10 != 9)
		{
			calc(b, digit);
			b--;
		}
		if (a == b)
		{
			calc(a, digit);
			break;
		}

		int inc = (b / 10) - (a / 10) + 1;
		for (int i = 0; i < 10; i++)
			ans[i] += inc * digit;
		digit *= 10;
		a /= 10; b /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/1019