#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n % 4 == 0 && (n % 100 != 0 || n % 400 == 0))
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}

// https://www.acmicpc.net/problem/2753

/*
simple problem
*/