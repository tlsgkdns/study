#include <iostream>

using namespace std;

long long pow(long long a, long long b, long long c)
{
	if (b == 0) return 1;

	long long n = pow(a, b / 2, c);
	long long tmp = n * n % c;

	return (b % 2 == 0) ? tmp : a * tmp % c;
}

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;

	cout << pow(a, b, c) << '\n';
}

// https://www.acmicpc.net/problem/1629