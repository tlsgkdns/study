#include <iostream>

using namespace std;

int main(void)
{
	long long a, b, c;
	cin >> a >> b >> c;
	if (c <= b)
	{
		cout << -1 << endl;
		return 0;
	}

	long long answer = a / (c - b);
	answer++;

	cout << answer << endl;
	return 0;
}

// https://www.acmicpc.net/problem/1712

/*
calculate
*/