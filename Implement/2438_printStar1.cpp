#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k < i; k++)
			cout << "*";
		cout << '\n';
	}

	return 0;
}

// https://www.acmicpc.net/problem/2438