#include <iostream>
using namespace std;
int main()
{
	int h, m;
	cin >> h >> m;
	if (m < 45)
	{
		h = (h == 0) ? 23 : (h - 1);
		m += 15;
	}
	else
		m -= 45;
	cout << h << " " << m << '\n';
}

// https://www.acmicpc.net/problem/2884

/*
Rest time
*/