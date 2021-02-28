#include <iostream>

using namespace std;


int main(void)
{
	int n, a, b;
	cin >> n;
	if (n % 10 != 0)
	{
		a = n / 10;
		b = n % 10;
	}
	else
	{
		a = n / 100;
		b = 10;
	}

	cout << a + b << '\n';
	return 0;
}

// https://www.acmicpc.net/problem/15873

/*
div and plus
*/