#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> fib;
	int n;
	cin >> n;

	fib.push_back(0);
	fib.push_back(1);

	for (int i = 2; i <= n; i++)
	{
		fib.push_back(fib[i - 1] + fib[i - 2]);
	}

	cout << fib[n] << endl;
}

// https://www.acmicpc.net/problem/2747

/*
first step to recursion
*/