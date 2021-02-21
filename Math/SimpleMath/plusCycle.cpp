#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(void)
{
	int n, cycle, tmp, answer = 0;
	cin >> n;
	tmp = n;
	do
	{
		int ten = (tmp / 10);
		int one = (tmp % 10);
		cycle = one * 10 + ((ten + one) % 10);
		answer++;
		tmp = cycle;
	} while (cycle != n);

	cout << answer << endl;
	return 0;
}
// https://www.acmicpc.net/problem/1110

/*
just calculate and repeat
this problem remind me of 1131(Gold, number) problem..
*/