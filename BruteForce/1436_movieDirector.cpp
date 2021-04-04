#include <iostream>

using namespace std;

int main()
{
	int n, cnt = 0, num = 665;
	cin >> n;
	while (cnt < n)
	{
		num++;
		int s = 0, tmp = num;
		while (tmp != 0)
		{
			if (tmp % 10 == 6) s++;
			else s = 0;
			if (s == 3)
			{
				cnt++;
				break;
			}
			tmp /= 10;
		}
	}
	cout << num << '\n';
}

// https://www.acmicpc.net/problem/1436

/*
simple BruteForce
*/