#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	while (n != 1)
	{
		if (n % 2 == 1) break;
		n /= 2;
	}

	cout << (n == 1) ? 1 : 0 << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/11966

/*
simple problem
*/