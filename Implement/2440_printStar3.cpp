#include <iostream>

using namespace std;

int N;

int main()

{
	cin >> N;
	for (int i = N; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
			cout << "*";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2440