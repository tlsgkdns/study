#include <iostream>
using namespace std;
int m[3] = { 300,60,10 }, a[3] = { 0,0,0 }, T;
int main()
{
	cin >> T;
	for (int i = 0; i < 3; i++)
		while ((T / m[i]) != 0)
		{
			T -= m[i];
			a[i]++;
		}
	if (T != 0) cout << -1 << '\n';
	else
	{
		for (int i = 0; i < 3; i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/10162