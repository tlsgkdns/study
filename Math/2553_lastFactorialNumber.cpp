#include <iostream>

using namespace std;

long long N, n = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		n *= i;
		n %= 10000000;
		while (n % 10 == 0) n /= 10;
	}
	cout << n % 10 << '\n';
}

// https://www.acmicpc.net/problem/2553