#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	int a, b, v;
	cin >> a >> b >> v;
	int pos = 0;
	int day = 0;

	int oneDay = a - b;

	v -= a;

	if (v <= 0)
	{
		day = 1;
	}
	else
	{
		if (v % oneDay == 0) day = (v / oneDay) + 1;
		else day = (v / oneDay) + 2;
	}

	cout << day << endl;

	return 0;
}

// https://www.acmicpc.net/problem/2869