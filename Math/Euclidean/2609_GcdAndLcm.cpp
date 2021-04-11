#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	if (a < b) swap(a, b);
	while (b != 0)
	{
		long long tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	long long a, b;
	cin >> a >> b;
	long long g = gcd(a, b);
	cout << g << '\n';
	cout << (a * b) / g << '\n';
}

// https://www.acmicpc.net/problem/2609

/*
standard Euclidean algorithm problem.
*/