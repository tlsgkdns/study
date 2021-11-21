#include <iostream>

using namespace std;
using ll = long long;

int fib[1500001];
const int MOD = 1000000;
const int PER = 1500000;

int main()
{
	ll n;
	cin >> n;
	fib[0] = 0; fib[1] = 1;
	for (int i = 2; i < PER; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	cout << fib[n % PER] << '\n';
}

// https://www.acmicpc.net/problem/2749