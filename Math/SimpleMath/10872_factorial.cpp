#include <iostream>

using namespace std;

int N;

int main()
{
	cin >> N;
	int a = 1;
	for (int i = N; i >= 1; i--) a *= i;
	cout << a << '\n';
}

// https://www.acmicpc.net/problem/10872