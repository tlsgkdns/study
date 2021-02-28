#include <iostream>
using namespace std;

int main(void)
{
	int k, n, m;
	cin >> k >> n >> m;

	int cost = k * n;

	int answer = (cost - m > 0) ? cost - m : 0;

	cout << answer << '\n';

	return 0;

}

// https://www.acmicpc.net/problem/10156
/*
simple problem
*/