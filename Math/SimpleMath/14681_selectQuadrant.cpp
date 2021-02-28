#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int x, y;
	int result = 0;
	cin >> x;
	cin >> y;

	if (x > 0 && y > 0)
		result = 1;
	else if (x < 0 && y > 0)
		result = 2;
	else if (x < 0 && y < 0)
		result = 3;
	else
		result = 4;

	cout << result << endl;
	return 0;
}

// https://www.acmicpc.net/problem/14681

/*
simple problem
*/