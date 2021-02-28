#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = n; i > 0; i--)
		cout << i << "\n";


	return 0;
}

// https://www.acmicpc.net/problem/2742

/*
to reduce time, line 9, line 12('\n') is important.
*/