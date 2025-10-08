#include <iostream>

using namespace std;

int K, a = 1, b = 0;

int main()
{
	cin >> K;
	while (K--)
	{
		int tmp = b;
		b += a;
		a = tmp;
	}
	cout << a << " " << b << '\n';
}

// https://www.acmicpc.net/problem/9625