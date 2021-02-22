#include <iostream>

using namespace std;


int main()
{
	int n, k;
	cin >> n;

	for (int i = 1; i <= 101; i++)
	{
		if (((i * i) + i + 1) == n) { cout << i << endl; break; }
	}
}

// https://www.acmicpc.net/problem/15667

/*
simple problem
*/