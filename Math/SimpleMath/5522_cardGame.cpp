#include <iostream>

using namespace std;

int main()
{
	int n, s = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		s += n;
	}
	cout << s << '\n';
}

// https://www.acmicpc.net/problem/5522