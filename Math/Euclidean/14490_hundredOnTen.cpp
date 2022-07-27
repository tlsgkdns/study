#include <iostream>
using namespace std;
int N, M;
char c;
int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	while (b > 0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	cin >> N >> c >> M;
	int g = gcd(N, M);
	cout << (N / g) << ":" << (M / g) << '\n';
}

// https://www.acmicpc.net/problem/14490