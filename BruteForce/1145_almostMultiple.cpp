#include <iostream>

using namespace std;

int N[5];

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> N[i];
	}
	for (int n = 1; ; n++)
	{
		int cnt = 0;
		for (int i = 0; i < 5; i++)
			cnt += (n % N[i] == 0);
		if (cnt >= 3)
		{
			cout << n << '\n';
			break;
		}
	}
}

// https://www.acmicpc.net/problem/1145