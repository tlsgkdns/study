#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
			cout << "*";
		cout << '\n';
	}
	for (int a = n - 1; a > 0; a--)
	{
		for (int b = a; b > 0; b--)
			cout << "*";
		cout << '\n';
	}

	return 0;
}
// https://www.acmicpc.net/problem/2523

/*
print star~~~~~~~~~~~~~
*/