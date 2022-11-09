#include <iostream>
#include <algorithm>
using namespace std;

int arr[7], num, m = 101, s = 0;
int main()
{
	for (int i = 0; i < 7; i++)
	{
		cin >> num;
		if (!(num % 2)) continue;
		m = min(num, m);
		s += num;
	}
	if (s == 0) cout << -1 << '\n';
	else cout << s << '\n' << m << '\n';
}

// https://www.acmicpc.net/problem/2576